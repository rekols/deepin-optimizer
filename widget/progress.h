/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2017 Rekols
 *
 * Author:     Rekols <rekols@foxmail.com>
 * Maintainer: Rekols <rekols@foxmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PROGRESS_H
#define PROGRESS_H

#include <QWidget>

class Progress : public QWidget
{
    Q_OBJECT
    Q_ENUMS(PercentStyle)

    Q_PROPERTY(int minValue READ getMinValue WRITE setMinValue)
    Q_PROPERTY(int maxValue READ getMaxValue WRITE setMaxValue)
    Q_PROPERTY(int value READ getValue WRITE setValue)

    Q_PROPERTY(int nullPosition READ getNullPosition WRITE setNullPosition)
    Q_PROPERTY(int borderWidth READ getBorderWidth WRITE setBorderWidth)

    Q_PROPERTY(double waterHeight READ getWaterHeight WRITE setWaterHeight)
    Q_PROPERTY(double waterDensity READ getWaterDensity WRITE setWaterDensity)

    Q_PROPERTY(bool showPercent READ getShowPercent WRITE setShowPercent)
    Q_PROPERTY(bool showFree READ getShowFree WRITE setShowFree)
    Q_PROPERTY(bool showSmallCircle READ getShowSmallCircle WRITE setShowSmallCircle)
    Q_PROPERTY(bool clockWise READ getClockWise WRITE setClockWise)

    Q_PROPERTY(QColor usedColor READ getUsedColor WRITE setUsedColor)
    Q_PROPERTY(QColor freeColor READ getFreeColor WRITE setFreeColor)
    Q_PROPERTY(QColor circleColor READ getCircleColor WRITE setCircleColor)
    Q_PROPERTY(QColor textColor READ getTextColor WRITE setTextColor)

public:
    enum PercentStyle {
        PercentStyle_Arc = 0,           //圆弧风格
        PercentStyle_Polo = 1,          //水池风格
        PercentStyle_Wave = 2,          //波纹风格
        PercentStyle_Arc_Polo = 3,      //圆弧水池风格
        PercentStyle_Arc_Wave = 4       //圆弧波纹风格
    };

    explicit Progress(QWidget *parent = 0);
    ~Progress();

protected:
    void paintEvent(QPaintEvent *);
    void drawCircle(QPainter *painter, int radius);
    void drawArc(QPainter *painter, int radius);
    void drawPolo(QPainter *painter, int radius);
    void drawWave(QPainter *painter, int radius);
    void drawText(QPainter *painter, int radius);

private:
    int maxValue;                   //最小值
    int minValue;                   //最大值
    int value;                      //目标值

    int nullPosition;               //起始角度
    int borderWidth;                //边框宽度

    double waterHeight;             //水波高度
    double waterDensity;            //水波密度

    bool showPercent;               //是否显示百分比
    bool showFree;                  //是否显示未使用进度
    bool showSmallCircle;           //是否显示小圆
    bool clockWise;                 //顺时针

    QColor usedColor;               //已使用百分比颜色
    QColor freeColor;               //未使用百分比颜色
    QColor circleColor;             //圆颜色
    QColor textColor;               //文字颜色

    PercentStyle percentStyle;      //进度样式风格

    double offset;                  //水波偏移量
    QTimer *timer;                  //定时器绘制动画

public:
    int getMinValue()               const;
    int getMaxValue()               const;
    int getValue()                  const;

    int getNullPosition()           const;
    int getBorderWidth()            const;

    double getWaterHeight()         const;
    double getWaterDensity()        const;

    bool getShowPercent()           const;
    bool getShowFree()              const;
    bool getShowSmallCircle()       const;
    bool getClockWise()             const;

    QColor getUsedColor()           const;
    QColor getFreeColor()           const;
    QColor getCircleColor()         const;
    QColor getTextColor()           const;

    PercentStyle getPercentStyle()  const;

    QSize sizeHint()                const;
    QSize minimumSizeHint()         const;

public Q_SLOTS:
    //设置范围值
    void setRange(int minValue, int maxValue);

    //设置最大最小值
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);

    //设置目标值
    void setValue(int value);

    //设置最小值位置
    void setNullPosition(int nullPosition);
    //设置边框宽度
    void setBorderWidth(int borderWidth);

    //设置水波高度
    void setWaterHeight(double waterHeight);
    //设置水波密度
    void setWaterDensity(double waterDensity);

    //设置是否显示百分比
    void setShowPercent(bool showPercent);
    //设置是否显示剩余进度
    void setShowFree(bool showFree);
    //设置是否显示小圆
    void setShowSmallCircle(bool showSmallCircle);
    //设置进度旋转方向
    void setClockWise(bool clockWise);

    //设置已使用百分比颜色
    void setUsedColor(const QColor &usedColor);
    //设置未使用百分比颜色
    void setFreeColor(const QColor &freeColor);
    //设置圆颜色
    void setCircleColor(const QColor &circleColor);
    //设置文本颜色
    void setTextColor(const QColor &textColor);

    //设置进度样式风格
    void setPercentStyle(PercentStyle percentStyle);

Q_SIGNALS:
    void valueChanged(int value);
};

#endif
