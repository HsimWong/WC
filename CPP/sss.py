# coding = utf-8

import time
from numpy import *
import _thread
import datetime
import random

time_multiple = 0.01
worktime = 560


class Point(object):
    st_timePrev: int

    def __init__(self, id, worktime):
        self.st_timePrev = 0

        self.id = id
        self.priority = -1
        self.worktime = worktime
        self.CNC_On = False

    # def __iter__(self):
    #   return self

    def detPriority(self, curPos):
        if (curPos < 0 | (curPos >= 4)):
            print("RGV position error")
        else:
            if ((curPos == floor((self.id) / 2))):
                if (curPos * 2 == self.id):
                    self.priority = 0
                elif (curPos * 2 + 1 == self.id):
                    self.priority = 1
            elif (abs(curPos - floor((self.id) / 2)) == 1):
                if ((curPos == 2) & ((self.id) / 2 > curPos)):
                    self.priority = 2;
                elif ((curPos == 2) & ((self.id) / 2 < curPos)):
                    self.priority = 3;
                elif ((curPos == 1) & ((self.id) / 2 < curPos)):
                    self.priority = 4;
                elif (curPos == 1) & (floor(self.id / 2) > curPos):
                    self.priority = 5;
                elif (curPos == 0)| (curPos == 3):
                    if ((self.id) % 2 == 0):
                        self.priority = 2;
                    else:
                        self.priority = 3;
            elif (abs(curPos - floor((self.id) / 2)) == 2):
                if ((self.id) % 2 == 0):
                    self.priority = 6;
                else:
                    self.priority = 7;
            elif (abs(curPos - floor((self.id) / 2)) == 3):
                if (((self.id) % 2) == 0):
                    self.priority = 8;
                else:
                    self.priority = 9;

    def workCNC(self):
        while (True):
            if(random.random() <= 0.01):
                self.CNC_On = True
                time.sleep(random.random()*10 + 10)
                self.CNC_On = False
            if (self.CNC_On == True):
                time_start = time.time()
                print("%s,%s" % (self.id, time_start))


                time.sleep(self.worktime * 0.01)

                self.CNC_On = False


class RGV(object):
    def __init__(self):
        self.currwork = 9
        self.destination = 9
        self.curPos = 0
        self.RGV_On = True
        print("""Please input fallowing parameters:\n
        (Separate each parameters with space)\n
        U1time  U2time  U3time  UpEven  UpOdd  washTime""")
        self.U1time = int(input("U1time"))
        self.U2time = int(input("U2time"))
        self.U3time = int(input("U3time"))
        self.UpEven = int(input("UpEven"))
        self.UpOdd = int(input("UpOdd"))
        self.washTime = int(input("washTime"))
        self.ptList = []
        self.ptWait = []

    # def ListGen(self):
    #     for i in range(8):
    #         npt = Point(i, worktime)
    #         npt.detPriority(self.curPos)
    #         self.ptList.append(npt)


    def WaitGen(self):
        for pt in self.ptList:
            if (pt.CNC_On == False) & (pt not in self.ptWait):

                self.ptWait.append(pt)
        for pt in self.ptWait:
            pt.detPriority(self.curPos)

    def Dest(self):
        try:
            minPript = self.ptWait[0]
            minPri = self.ptWait[0].priority
            minInd = 0

            for i in range(len(self.ptWait) - 1):
                if self.ptWait[i + 1].priority < minPri:
                    minPri = self.ptWait[i + 1]
                    minInd = i + 1
                    minPri = minPri.priority
            del self.ptWait[minInd]
            self.destination = minPript.id
        except:
            z = 0

    def move(self):

        unit = abs(floor(self.destination / 2 - self.curPos))
        ret = {0: 0, 1: self.U1time, 2: self.U2time, 3: self.U3time}
        time.sleep((ret[unit] * 0.01))
        self.currwork = self.destination
        self.curPos = floor(self.currwork / 2)

    def wash(self):
        time.sleep((self.washTime) * 0.01)

    def UpDown(self):
        ret = {1: self.UpEven, 0: self.UpOdd}
        odd = (self.currwork)%2
        time.sleep((ret[odd]) * 0.01)

    def RGV_Go(self):
        # self.ListGen()
        while (self.RGV_On):
            self.WaitGen()
            self.Dest()
            if self.destination <= 7 & self.destination >= 0:
                # timeUp = datetime.datetime.now()
                # print("CNC_Num Up:" + str(self.destination))

                self.move()

                self.currwork = self.destination
                self.curPos = floor(self.currwork / 2)
                self.UpDown()
                self.ptList[self.destination].CNC_On = True
                timeDown = datetime.datetime.now()
                self.wash()
            else:
                continue


def RunCNC(Point):
    # print("1")
    # print("1")
    # s = (random.random())
    # print(s)
    while True:
        if Point.CNC_On:
            if double(random.random()) >= 0.990:
                time_s = time.time()
                Point.CNC_On = True
                # print("2")
                print("f")
                time.sleep(int((random.random() * 10 * 60+ 600) * 0.01))
                time_e = time.time()
                s = ("%s,%s,%s\n" % (Point.id, str(int(floor((time_s - time_init)* 100))),str(int(floor((time_e - time_init)* 100)))))
                with open('3_1_fault.txt','a+') as f2:
                    f2.write(s)
                Point.CNC_On = False
            else:
                time_start = time.time()

                s = ("%s,%s,%s\n" % (
                Point.id, int(floor((Point.st_timePrev - time_init)
                                       * 100)), int(floor(100 * (time_start - time_init)))))
                with open('3_1.txt','a+') as f:
                    f.write(s)
                print(s)
                time.sleep(Point.worktime * 0.01)
                Point.st_timePrev = time_start
                Point.CNC_On = False




def RunRGV(RGV):
    RGV.RGV_Go()


if __name__ == '__main__':
    txtName = '3_1.txt'
    # f = open(txtName,'a')
    # f2 = open('3_1fault.txt','a')
    time_init = time.time()
    rgv = RGV()
    ini_time = datetime.datetime.now().strftime("%H:%M:%S.%f")
    for i in range(8):
        CNC_entity = Point(i, worktime)
        rgv.ptList.append(CNC_entity)
        time_init = time.time()
        _thread.start_new_thread(RunCNC, (CNC_entity,))
    _thread.start_new_thread(RunRGV, (rgv,))

    time.sleep(288)
    # f.close()
    # f2.close


