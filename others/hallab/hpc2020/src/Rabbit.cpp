﻿//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  (C)HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください。
//------------------------------------------------------------------------------

#pragma once
#include "Rabbit.hpp"

//------------------------------------------------------------------------------
namespace hpc {

//------------------------------------------------------------------------------
Rabbit::Rabbit()
: mPosition()
, mPower(1.0f)
{
}

//------------------------------------------------------------------------------
Rabbit::Rabbit(const Vector2& aPos)
: mPosition(aPos)
, mPower(1.0f)
{
}

//------------------------------------------------------------------------------
const Vector2& Rabbit::pos() const
{
    return mPosition;
}

void Rabbit::setPos(const Vector2& aPos)
{
    mPosition = aPos;
}

//------------------------------------------------------------------------------
float Rabbit::power() const
{
    return mPower;
}

//------------------------------------------------------------------------------
void Rabbit::setPower(float aPower)
{
    mPower = aPower;
}

} // namespace
// EOF
