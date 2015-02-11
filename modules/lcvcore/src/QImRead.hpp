/****************************************************************************
**
** Copyright (C) 2014 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of Live CV application.
**
** GNU General Public License Usage
** 
** This file may be used under the terms of the GNU General Public License 
** version 3.0 as published by the Free Software Foundation and appearing 
** in the file LICENSE.GPL included in the packaging of this file.  Please 
** review the following information to ensure the GNU General Public License 
** version 3.0 requirements will be met: http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/

#ifndef QMATSOURCE_HPP
#define QMATSOURCE_HPP

#include <QQuickItem>
#include "QMat.hpp"
#include "QMatDisplay.hpp"

class QImRead : public QMatDisplay{

    Q_OBJECT
    Q_PROPERTY(QString file     READ file    WRITE setFile    NOTIFY fileChanged)
    Q_PROPERTY(int     iscolor  READ iscolor WRITE setIscolor NOTIFY iscolorChanged)

    Q_ENUMS(Load)

public:
    enum Load{
        CV_LOAD_IMAGE_UNCHANGED  = -1,
        CV_LOAD_IMAGE_GRAYSCALE  =  0,
        CV_LOAD_IMAGE_COLOR      =  1,
        CV_LOAD_IMAGE_ANYDEPTH   =  2,
        CV_LOAD_IMAGE_ANYCOLOR   =  4
    };

public:
    explicit QImRead(QQuickItem *parent = 0);
    ~QImRead();

    const QString& file() const;
    void setFile(const QString& file);

    const int& iscolor() const;
    void setIscolor(const int& iscolor);
    
signals:
    void iscolorChanged();
    void fileChanged();

protected:
    void componentComplete();

private:
    void loadImage();

    QString m_file;
    int     m_iscolor;
    
};

inline const int& QImRead::iscolor() const{
	return m_iscolor;
}

inline void QImRead::setIscolor(const int& iscolor){
	if (m_iscolor != iscolor){
		m_iscolor = iscolor;
		emit iscolorChanged();
        loadImage();
	}
}

inline void QImRead::setFile(const QString &file){
    if ( file != m_file ){
        m_file = file;
        emit fileChanged();
        loadImage();
    }
}

inline const QString &QImRead::file() const{
    return m_file;
}

#endif // QMATSOURCE_HPP
