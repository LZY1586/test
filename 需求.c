const uint8_t cloud[18] = {2,3,32,31,30,29,34,35,36,37,38,39,67,66,65,64,63,62}   //云朵

const uint8_t weatherColor[13][5][2] = {     //天气图标着色  {像素点,颜色}
  {{3,2},{4,2},{30,2},{29,2}},         //多云
  {{70,4}},                            //小雨
  {{69,4},{72,4}},                     //中雨
  {{68,4},{70,4},{72,4}},              //大雨
  {{68,4},{70,4},{71,4},{73,4}},       //暴雨
  {{3,2},{4,2},{30,2},{29,2},{70,4}},  //阵雨
  {{69,2},{72,4}},                     //雷阵雨
  {{69,8},{72,4}},                     //雨夹雪
  {{70,8}},                            //小雪
  {{69,8},{72,8}},                     //中雪
  {{68,8},{70,8},{72,8}},              //大雪
  {{68,8},{70,8},{71,8},{73,8}},       //暴雪
  {{68,1},{70,1},{71,1},{73,1}},       //冰雹
};

uint32_t color[9] = {红,橙,黄,绿,蓝,靛,紫,灰,白};

void displayWeather(){
  uint8_t i;
  if(晴){
    setRangeColor(1,4,color[1]);
    setPixelColor(32,color[2]);
    setRangeColor(30,31,color[1]);
    setPixelColor(29,color[2]);
    setPixelColor(35,color[2]);
    setRangeColor(36,37,color[1]);
    setPixelColor(38,color[2]);
    setRangeColor(63,66,color[1]);
  }else if(阴){
    for(i = 0; i < 18; i++){
      setPixelColor(cloud[i],color[7]);
    }
  }else if(雾){
    setRangeColor(0,6,color[8]);
    setRangeColor(34,39,color[8]);
    setRangeColor(68,73,color[8]);
  }else if(雾霾){
    setRangeColor(0,6,color[8]);
    setRangeColor(28,39,color[8]);
    setRangeColor(62,73,color[8]);
  }else{
    for(i = 0; i < 18; i++){    //基础模型
      setPixelColor(cloud[i],color[7]);
    }
    for(i = 0;i < len; i++){     //上色
      setPixelColor(weatherColor[天气][i][0],color[weatherColor[天气][i][1]]);
    }
  }
}


uint8_t minute,hour,day,month,week;
rtc.getNowTime();

if(minute != rtc.minute()){        //每分运行一次
  minute = rtc.minute();
  //清除画面、显示时间
  if(hour != rtc.hour()){        //每时运行一次
    hour = rtc.hour()
    //改变灯颜色
    color = yan[hour];
    //调节灯亮度
    if(hour >= 8 && hour <= 22) //高亮度;
    else //低亮度;
    
    if(day != rtc.day()){        //每天运行一次
      day = rtc.day()
      //校准时间,校准失败退出
      getTimeFromNTP();

      if(month != rtc.month()){  //每月运行一次
        month = rtc.month();
        /*更改日期颜色*/
        if(month <= 5 && month >= 3) printf("春");
        else if(month <= 8 && month >= 6)printf("夏");
        else if(month <= 11 && month >= 9)printf("秋");
        else printf("冬");
      }
    }
  }
}

void getTimeFromNTP()
{
    struct tm timeinfo;
    if(!getLocalTime(&timeinfo)){
        Serial.println("Failed to obtain time");
        return;
    }
    
    rtc.setYear(timeinfo.tm_year - 100);
    rtc.setMonth(timeinfo.tm_mon + 1);
    rtc.setDate(timeinfo.tm_mday);
    rtc.setHour(timeinfo.tm_hour, e24hours);
    rtc.setMinute(timeinfo.tm_min);
    rtc.setSecond(timeinfo.tm_sec);
    rtc.adjust();
    
}


/*每时运行一次*/
//根据时间改变时间颜色、改变灯亮度

/*每天运行一次*/
//根据星期改变点的颜色
//校准时间

/*每月运行*/
//更具四季改变日期的颜色  //根据二十四节气？

/*超过阈值*/
//温度自动颜色
//湿度自动颜色

//节日提醒？

//获取网络天气、温湿度？
//恶劣天气预警？