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

#ifndef CLEAR_PAGE_H
#define CLEAR_PAGE_H

#include <QWidget>
#include <QStackedLayout>
#include "clear_page/scan_page.h"
#include "clear_page/cleaner_page.h"
#include "clear_page/cfinish_page.h"

class ClearWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClearWidget(QWidget *parent = nullptr);

private:
    QStackedLayout *layout;
    ScanPage *scanPage;
    CleanerPage *cleanerPage;
    CFinishPage *cfinishPage;

private slots:
    void scanButtonClicked();
    void backButtonClicked();
    void clearFinished(QString tips);
};

#endif // CLEAR_PAGE_H
