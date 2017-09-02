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

#ifndef MEMORY_MONITOR_H
#define MEMORY_MONITOR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include "widget/progress.h"

class MemoryMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryMonitor(QWidget *parent = nullptr);

    void setPercentValue(const int &value);
    void setMemoryInfo(const QString &info);

private:
    QVBoxLayout *layout;
    Progress *progress;
    QLabel *infoLabel;
};

#endif // MEMORY_MONITOR_H
