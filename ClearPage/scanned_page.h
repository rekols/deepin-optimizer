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

#ifndef CLEANER_PAGE_H
#define CLEANER_PAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QFileInfo>
#include <QPushButton>

class ScannedPage : public QWidget
{
    Q_OBJECT

public:
    enum CleanCategories {
        PACKAGE_CACHE,
        CRASH_REPORTS,
        APPLICATION_LOGS,
        APPLICATION_CACHES,
        TRASH
    };

    explicit ScannedPage(QWidget *parent = nullptr);

    void start();

private:
    QVBoxLayout *layout;
    QHBoxLayout *buttonLayout;
    QPushButton *backButton;
    QTreeWidget *resultTree;

    QIcon defaultIcon;
    QPushButton *clearButton;

private slots:
    void init();
    void addTreeRoot(const CleanCategories &cat, const QString &title, const QFileInfoList &infos, bool noChild = false);
    void addTreeChild(const CleanCategories &cat, const QString &text, const quint64 &size);
    void addTreeChild(const QString &data, const QString &text, const quint64 &size, QTreeWidgetItem *parent);
    bool cleanValid();
    void clearButtonClicked();
    void treeItemClicked(QTreeWidgetItem *item, const int &column);
    void systemScan();

signals:
    void backButtonClicked();
    void clearFinished(QString info);
    void scanFinished();
};

#endif // CLEANER_PAGE_H
