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

#include "ads_globals.h"
#include "DockManager.h"
#include "DockWidget.h"

#include "mainwindow.h"

static void initStyles() {
   Q_INIT_RESOURCE(styles);
}

namespace Raster {
   MainWindow::MainWindow() : QMainWindow() {
      initStyles();
      ads::CDockManager::setConfigFlag(ads::CDockManager::FocusHighlighting, true);
      this->m_dock = new ads::CDockManager(this);

      QFile f(":/styles/docking.css");
      if (!f.exists()) {
         qWarning() << "docking.css does not exist";
      }
      if (!f.open(QFile::ReadOnly | QFile::Text)) {
         qWarning() << "failed to open docking.css";
      }
      const QString style = QString::fromUtf8(f.readAll());
      m_dock->setStyleSheet(style);
      f.close();

      QPalette palette = QApplication::palette();
      palette.setColor(QPalette::Window, QColor(29, 29, 29));
      QApplication::setPalette(palette);

      QLabel* w = new QLabel("Widget!!");
      auto dockWidget = m_dock->createDockWidget("WWW");
      dockWidget->setWidget(w);
      m_dock->addDockWidget(ads::BottomDockWidgetArea, dockWidget);
   }
}