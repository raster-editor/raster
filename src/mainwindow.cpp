/*
   Copyright (C) 2025 Letik Kirill

   This file is part of Raster.
   Raster is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Raster is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Raster.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QApplication>
#include <QResource>
#include <QFile>
#include <QPalette>
#include <QMessageBox>
#include <qapplication.h>
#include <qpushbutton.h>

#include "ads_globals.h"
#include "DockManager.h"
#include "DockWidget.h"
#include "IconProvider.h"

#include "mainwindow.h"

static void initResources() {
   Q_INIT_RESOURCE(styles);
   Q_INIT_RESOURCE(icons);
}

namespace Raster {
   MainWindow::MainWindow() : QMainWindow() {
      initResources();
      ads::CDockManager::setConfigFlags(ads::CDockManager::DefaultOpaqueConfig);
      ads::CDockManager::setConfigFlag(ads::CDockManager::RetainTabSizeWhenCloseButtonHidden, true);
      ads::CDockManager::setConfigFlag(ads::CDockManager::AlwaysShowTabs, true);
      ads::CDockManager::setConfigFlag(ads::CDockManager::AllTabsHaveCloseButton, false);
      ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHasTabsMenuButton, true);
      ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHasCloseButton, false);
      ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHasUndockButton, false);
      ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHideDisabledButtons, true);
      ads::CDockManager::setConfigFlag(ads::CDockManager::DoubleClickUndocksWidget, false);
      ads::CDockManager::setConfigFlag(ads::CDockManager::FocusHighlighting, true);
      ads::CDockManager::setConfigFlag(ads::CDockManager::OpaqueSplitterResize, true);

      this->m_dock = new ads::CDockManager(this);

      /* avoid cluttering current scope */
      {
         QFile f(":/styles/docking.css");
         if (!f.exists()) {
            qWarning() << "docking.css does not exist";
         }
         if (!f.open(QFile::ReadOnly | QFile::Text)) {
            qWarning() << "failed to open docking.css";
         }
         const QString style = QString::fromUtf8(f.readAll());
         m_dock->setStyleSheet("");
         m_dock->setStyleSheet(style);
         f.close();
      }

      {
         QFile f(":/styles/ui.css");
         if (!f.exists()) {
            qWarning() << "ui.css does not exist";
         }
         if (!f.open(QFile::ReadOnly | QFile::Text)) {
            qWarning() << "failed to open ui.css";
         }
         const QString style = QString::fromUtf8(f.readAll());
         setStyleSheet(style);
         f.close();
      }

      QPalette palette = QApplication::palette();
      palette.setColor(QPalette::Window, QColor(29, 29, 29));
      palette.setColor(QPalette::WindowText, QColor(208, 208, 208));
      palette.setColor(QPalette::Text, QColor(208, 208, 208));
      palette.setColor(QPalette::BrightText, QColor(255, 255, 255));
      palette.setColor(QPalette::Highlight, QColor(64, 148, 238));
      palette.setColor(QPalette::Light, QColor(164, 164, 164));
      palette.setColor(QPalette::Midlight, QColor(128, 128, 128));
      palette.setColor(QPalette::Dark, QColor(75, 75, 75));
      palette.setColor(QPalette::Mid, QColor(48, 48, 48));
      palette.setColor(QPalette::Shadow, QColor(0, 0, 0));
      palette.setColor(QPalette::Button, QColor(0, 0, 0));
      palette.setColor(QPalette::ButtonText, QColor(186, 186, 186));
      QApplication::setPalette(palette);

      auto dockWidget = m_dock->createDockWidget("highfashion");
      dockWidget->setWidget( new QLabel("Widget!!"));
      m_dock->addDockWidget(ads::BottomDockWidgetArea, dockWidget);

      auto dockWidget1 = m_dock->createDockWidget("aquamarine");
      dockWidget1->setWidget( new QPushButton("Testing Push Buttons"));
      m_dock->addDockWidget(ads::LeftDockWidgetArea, dockWidget1);

      auto dockWidget2 = m_dock->createDockWidget("timeslikethese");
      dockWidget2->setWidget(new QLabel("Widget!!"));
      m_dock->addDockWidget(ads::RightDockWidgetArea, dockWidget2);
   }
}