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

#include "cpu_monitor.h"

CPUMonitor::CPUMonitor(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    progress = new Progress();
    QLabel *tips = new QLabel("CPU");
    tips2 = new QLabel("Loading");

    QFont font;
    font.setPointSize(20);
    tips->setFont(font);
    font.setPointSize(15);
    tips2->setFont(font);

    layout->addWidget(tips, 0, Qt::AlignHCenter);
    layout->addWidget(progress, 0, Qt::AlignHCenter);
    layout->addWidget(tips2, 0, Qt::AlignHCenter);

    progress->setCircleColor(QColor("#F3F3F3"));
    progress->setTextColor(QColor("#303030"));
    progress->setUsedColor(QColor("#2CA7F8"));
    progress->setPercentStyle(Progress::PercentStyle_Polo);
}

void CPUMonitor::setPercentValue(const int &value)
{
    progress->setValue(value);

    if (value > 0 && value < 50)
        tips2->setText("CPU Idle");
    else if (value > 50 && value < 100)
        tips2->setText("CPU Busy");
}
