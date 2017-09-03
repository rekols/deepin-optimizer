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

#include "clear_widget.h"

ClearWidget::ClearWidget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QStackedLayout(this);
    scanPage = new ScanPage();
    cleanerPage = new CleanerPage();
    cfinishPage = new CFinishPage();

    layout->addWidget(scanPage);
    layout->addWidget(cleanerPage);
    layout->addWidget(cfinishPage);

    connect(scanPage, &ScanPage::scanButtonClicked, this, &ClearWidget::scanButtonClicked);
    connect(cleanerPage, &CleanerPage::backButtonClicked, this, &ClearWidget::backButtonClicked);
    connect(cfinishPage, &CFinishPage::backButtonClicked, this, &ClearWidget::backButtonClicked);
    connect(cleanerPage, &CleanerPage::clearFinished, this, &ClearWidget::clearFinished);

    layout->setCurrentIndex(0);
}

void ClearWidget::scanButtonClicked()
{
    layout->setCurrentIndex(1);

    cleanerPage->start();
}

void ClearWidget::backButtonClicked()
{
    layout->setCurrentIndex(0);
}

void ClearWidget::clearFinished(QString tips)
{
    cfinishPage->setTips(tips);

    layout->setCurrentIndex(2);
}
