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

#include "finish_page.h"

FinishPage::FinishPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    tipsIcon = new QLabel();
    tips = new QLabel();
    backButton = new QPushButton("back");
    tips->setStyleSheet(" QLabel { font-size: 18px; } ");

    tipsIcon->setPixmap(QPixmap(":/images/check.svg"));
    backButton->setFixedSize(300, 50);
    backButton->setObjectName("BlueButton");

    layout->addStretch();
    layout->addWidget(tipsIcon, 0, Qt::AlignCenter);
    layout->addSpacing(20);
    layout->addWidget(tips, 0, Qt::AlignCenter);
    layout->addStretch();
    layout->addWidget(backButton, 0, Qt::AlignCenter);
    layout->addStretch();

    connect(backButton, &QPushButton::clicked, this, &FinishPage::backButtonClicked);
}

void FinishPage::setTips(const QString &text)
{
    tips->setText(text);
}
