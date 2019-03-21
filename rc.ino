// 引用LiquidCrystal Library
  #include <LiquidCrystal.h>
  String rx_buffer; 
  // 建立LiquidCrystal 的变数lcd
  // LCD 接脚: rs, enable, d4, d5, d6, d7 
  // 对应到Arduino 接脚: 12, 11, 5, 4, 3, 2
  LiquidCrystal lcd(3, 5, 10, 11, 12, 13);
   
  void setup() 
  {
    // 设定LCD 的行列数目(2 x 16)
    lcd.begin(16, 2);
   
    // 列印"Hello World" 讯息到LCD 上
    lcd.print("hello, world!");

    Serial.begin(9600);
    Serial.flush();
   }
   
  void loop() 
 {
    // 将光标设到第5列，第2行(第一列第一行为0，0)，设置显示到屏幕第二行中间
    lcd.setCursor(6, 1);
    lcd.print("test");
    while (Serial.available() > 0){
      rx_buffer += char(Serial.read());
      delay(2);
    }
    if(rx_buffer.length() > 0){
      Serial.println(rx_buffer);
      lcd.print(rx_buffer);
      rx_buffer = "";
    }
    // 打印Arduino 重开之后经过的秒数
    
  }
