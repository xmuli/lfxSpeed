/*
 * Copyright (c) 2020 xmuli
 *
 * Author:  xmuli(偕臧) xmulitech@gmail.com
 * GitHub:  https://github.com/xmuli
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * */

#ifndef SPEEDINFO_H
#define SPEEDINFO_H

#include <QObject>

class QString;
class QTimer;

class SpeedInfo: public QObject
{
    Q_OBJECT
public:
    enum RateUnit {
        RateBit,
        RateByte,
        RateKb,
        RateMb,
        RateGb,
        RateTb,
        RateUnknow
    };
    Q_ENUM(RateUnit)

    enum Sensitive {
        Default,  // 大小写混合
        Upper,    // 全部大写
        Lower     // 全部小写
    };

public:
    SpeedInfo(QObject *parent = nullptr);

    void netRate(long &netDown, long &netUpload);
    void cpuRate(long &cpuAll, long &cpuFree);
    void memoryRate(long &memory, long &memoryAll, long &swap, long &swapAll);
    QString setRateUnitSensitive(RateUnit unit, Sensitive sensitive = SpeedInfo::Default);
    double autoRateUnits(long speed, RateUnit &unit);
    void uptime(double &run, double &idle);
    QString autoTimeUnits(double s);
};

#endif // SPEEDINFO_H
