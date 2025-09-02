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

#include "mainwindow.h"
#include "DockManager.h"
#include "ads_globals.h"
#include <qnamespace.h>

namespace Raster {
   MainWindow::MainWindow() : QMainWindow() {
      this->m_dock = new ads::CDockManager(this);

      ads::CDockWidget* CentralDockWidget = m_dock->createDockWidget("CentralWidget");
      CentralDockWidget->setWidget(new QWidget(this));
      CentralDockWidget->setFeature(ads::CDockWidget::NoTab, true);
      auto* CentralDockArea = m_dock->setCentralWidget(CentralDockWidget);

      QLabel* w = new QLabel("Widget!!");
      auto dockWidget = m_dock->createDockWidget("WWW");
      dockWidget->setWidget(w);
      m_dock->addDockWidget(ads::BottomDockWidgetArea, dockWidget);

   }
}