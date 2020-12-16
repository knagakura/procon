#ifndef OUTPUT_ACTUAL_STATE_OF_POWER
#define OUTPUT_ACTUAL_STATE_OF_POWER

#include "generator_B.lib/random_number.hpp"
#include "generator_B.lib/constraints.hpp"

#include <cinttypes>
#include <vector>
#include <random>

void output_actual_state_of_power(random_number &rnd, size_t DAY_TYPE, size_t pw_type, std::vector<size_t> &nanos, std::vector<size_t> &patterns, bool remove_randomness, FILE *fp) {

  // T_MAX を N_DIV 個数の区間に分ける。
  // 各区間に応じて、expected + delta の電力供給量になる

  assert(T_MAX % N_DIV == 0);
  size_t len = T_MAX / N_DIV; // 一区画あたりのながさ

  // 平均 0、分散 DISPERSION の正規分布から生成する
  std::normal_distribution<> dist(0, std::sqrt(DISPERSION));
  std::default_random_engine engine(rnd.next_uint());

  // event が生じる時間区間とナノグリッドを選択する：岡本： 2020/12/09
  std::uniform_real_distribution<double> unit_random(0, 1);
  const double p_event = DAY_TYPE == 1 || DAY_TYPE == 3 ? 0.1 : 0;
  std::vector<std::vector<bool>> event_pos(N_DIV, std::vector<bool>(N_GRID, false)); 
  std::vector<size_t> selector(N_GRID); std::iota(selector.begin(), selector.end(), 0);
  for(size_t k = 0; k < N_DIV; ++k){
    if (unit_random(engine) < p_event){
      std::shuffle(selector.begin(), selector.end(), engine);
      for(size_t i = 0; i < N_EVENT; ++i)
        event_pos[k][selector[i]] = true;
    }
  }

  for (size_t i = 0; i < T_MAX; i++) {
    size_t kukaku = i / len;
    //      assert(0 <= kukaku and kukaku < N_DIV);
    assert(kukaku < N_DIV);

    for (size_t j = 0; j < N_GRID; j++) {
      size_t weather = (DAY_TYPE <= 1 ? 0 : 1);
      size_t pattern = patterns[j] - 1;
      size_t id = nanos[j];

      int pw = PW[pw_type][weather][pattern][kukaku]; // 予測電力増加
      if(!remove_randomness){
        // event の仕様を変更：岡本：2020/12/07
        // DAY_TYPE == 1 => ゲリラ豪雨により、DELTA_EVENT 減少
        // DAY_TYPE == 3 => 予想外の晴れにより、DELTA_EVENT 減少
        if(event_pos[kukaku][j])
          pw += (DAY_TYPE == 1 ? -1 : DAY_TYPE == 3 ? 1 : 0)*DELTA_EVENT;

        // ただのcastでは不具合が起こる模様：岡本
        int add = round(dist(engine));
        pw += add;
      }
      fprintf(fp, "%zu %d", id, pw); // 頂点 id, 電力量
      if (j + 1 == N_GRID) {
        fprintf(fp, "\n");
      } else {
        fprintf(fp, " ");
      }
    }
  }
  
  fflush(fp);
}

#endif
