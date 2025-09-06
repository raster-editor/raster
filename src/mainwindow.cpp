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
#include <QAction>
#include <QMenuBar>
#include <qboxlayout.h>

#include "ads_globals.h"
#include "DockManager.h"
#include "DockWidget.h"

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

      applyStyleSheets();

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
      QApplication::setStyle("fusion");

      createActions();
      createMenus();

      auto dockWidget = m_dock->createDockWidget("highfashion");
      auto defaultDialogButton = new QPushButton("OK");
      defaultDialogButton->setAutoDefault(true);
      defaultDialogButton->setDefault(true);
      defaultDialogButton->setProperty("role", "dialog");
      dockWidget->setWidget(defaultDialogButton);
      dockWidget->setContentsMargins(25, 25, 25, 25);
      m_dock->addDockWidget(ads::BottomDockWidgetArea, dockWidget);

      auto dockWidget1 = m_dock->createDockWidget("aquamarine");
      dockWidget1->setWidget( new QPushButton("Testing Push Buttons"));
      dockWidget1->setContentsMargins(25, 25, 25, 25);
      m_dock->addDockWidget(ads::LeftDockWidgetArea, dockWidget1);

      auto dockWidget2 = m_dock->createDockWidget("timeslikethese");
      auto ordinaryDialogButton = new QPushButton("Cancel");
      ordinaryDialogButton->setProperty("role", "dialog");
      auto layout = new QHBoxLayout();
      layout->addWidget(ordinaryDialogButton);
      auto holder = new QWidget();
      holder->setLayout(layout);
      dockWidget2->setWidget(holder);
      dockWidget2->setContentsMargins(25, 25, 25, 25);
      m_dock->addDockWidget(ads::RightDockWidgetArea, dockWidget2);
   }

   void MainWindow::applyStyleSheets() {
      QFile dockingFile(":/styles/docking.css");
      if (!dockingFile.exists()) {
         qWarning() << "docking.css does not exist";
      }
      if (!dockingFile.open(QFile::ReadOnly | QFile::Text)) {
         qWarning() << "failed to open docking.css";
      }
      const QString dockingStyle = QString::fromUtf8(dockingFile.readAll());
      m_dock->setStyleSheet("");
      m_dock->setStyleSheet(dockingStyle);
      dockingFile.close();

      QFile appStyle(":/styles/ui.css");
      if (!appStyle.exists()) {
         qWarning() << "ui.css does not exist";
      }
      if (!appStyle.open(QFile::ReadOnly | QFile::Text)) {
         qWarning() << "failed to open ui.css";
      }
      const QString style = QString::fromUtf8(appStyle.readAll());
      setStyleSheet(style);
      appStyle.close();
   }

   void MainWindow::createActions() {
      m_exitAction = new QAction(tr("Exit"), this);
      connect(m_exitAction, SIGNAL(QAction::triggered), this, SLOT(exit));
   }

   void MainWindow::createMenus() {
      auto file = menuBar()->addMenu(tr("File"));
      file->addAction(m_exitAction);
   }

   void MainWindow::exit() {
      QApplication::quit();
   }
}