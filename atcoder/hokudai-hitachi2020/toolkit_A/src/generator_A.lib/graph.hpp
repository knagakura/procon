#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <cstdint>
#include <cstddef>
#include <algorithm>
#include "generator_A.lib/node.hpp"

class edge {
public:
  using cost_type = int_fast64_t;
  static const cost_type INF = 1LL << 28;
  
  size_t src, dst;
  cost_type cost;
  int bit;
  
  edge() : cost(INF) {}
  edge(size_t u, size_t v, cost_type c) : src(u), dst(v), cost(c), bit(0) {}
  edge(size_t u, size_t v, cost_type c, int b) : src(u), dst(v), cost(c), bit(b) {}
};

const edge::cost_type INF = 1LL << 28; // ?

template <typename edge_type>
class graph {
public:
  using cost_type = typename edge_type::cost_type;
  std::vector< std::vector<edge_type> > g;
  std::vector<node> nodes;
  // std::vector<cost_type> f; // frequency

  graph() = default;
  graph(size_t N) : g(N), nodes(N) {
    for (size_t i = 0; i < N; i++) {
      nodes[i].type = 0;
      //nodes[i].type = -1;
    }
  }
  // graph(size_t N, std::vector<cost_type> freq) : g(N), f(freq) { sort_edges(); }
  graph(const graph &g_) : g(g_.g), nodes(g_.nodes) { sort_edges(); }

  graph<edge_type>& operator=(const graph<edge_type>&g_){
    g = g_.g;
    nodes = g_.nodes;
    sort_edges();
    return *this;
  }

  size_t size() const { return g.size(); }
  const std::vector<edge_type>& operator[](int k) const { return g[k]; }
  std::vector<edge_type>& operator[](int k) { return g[k]; }

  void add_edge(size_t u, size_t v, cost_type c) {
    g[u].emplace_back(u, v, c);
  }
  void add_edge(size_t u, size_t v, cost_type c, int b) {
    g[u].emplace_back(u, v, c, b);
  }
  void set_node(size_t u, node n) {
    nodes[u] = n;
  }

  void sort_edges() {
    for(size_t i=0; i<g.size(); i++) {
      std::sort(g[i].begin(), g[i].end(), [](edge_type a, edge_type b) {
	  return a.dst < b.dst;
	});
    }
  }

  // 頂点 u と直接結ばれている辺であって、端点が v であるもの (のインデックス) を返す
  /*int find(size_t u, size_t v) const {
    size_t lb = 0, ub = g[u].size();
    while(ub - lb > 1) {
      size_t mid = (ub + lb) >> 1;
      if(g[u][mid].dst <= v) lb = mid;
      else ub = mid;
    }

    if(g[u][lb].dst == v) return lb;
    else return -1;
  }*/
  int find(size_t u , size_t v ){//二部探索
	  for(size_t i = 0;i<g[u].size();i++){
		  if( g[u][i].dst == v ) return i;
	  }
	  return -1;
  }

  void print_all_nodes(FILE *fp){
	  for( auto i:nodes ){
		  if( i.is_grid() )// not normal grid
		  //if( i.type != -1 )// not normal grid
		  i.print(fp);
	  }
  }
};

#endif
