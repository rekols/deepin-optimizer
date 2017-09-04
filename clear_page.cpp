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

#include "clear_page.h"

ClearPage::ClearPage(QWidget *parent)
    : QWidget(parent)
{
    layout = new QStackedLayout(this);
    scanPage = new ScanPage();
    scannedPage = new ScannedPage();
    finishPage = new FinishPage();
    loadPage = new LoadPage();

    layout->addWidget(scanPage);
    layout->addWidget(scannedPage);
    layout->addWidget(finishPage);
    layout->addWidget(loadPage);

    connect(scanPage, &ScanPage::scanButtonClicked, this, &ClearPage::scanButtonClicked);
    connect(scannedPage, &ScannedPage::backButtonClicked, this, &ClearPage::backButtonClicked);
    connect(finishPage, &FinishPage::backButtonClicked, this, &ClearPage::backButtonClicked);
    connect(scannedPage, &ScannedPage::clearFinished, this, &ClearPage::clearFinished);
    connect(scannedPage, &ScannedPage::scanFinished, this, &ClearPage::scanFinished);

    layout->setCurrentIndex(0);
}

void ClearPage::scanButtonClicked()
{
    layout->setCurrentIndex(3);
    loadPage->play();

    scannedPage->start();
}

void ClearPage::backButtonClicked()
{
    layout->setCurrentIndex(0);
}

void ClearPage::clearFinished(QString tips)
{
    finishPage->setTips(tips);

    layout->setCurrentIndex(2);
}

void ClearPage::scanFinished()
{
    layout->setCurrentIndex(1);
}
