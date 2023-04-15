
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <string.h>
bool f = 0;
bool b = 0;
bool s = 0; 
String ssid = "test";
String password = "123456789";
IPAddress local_IP(192, 168, 2, 22);
IPAddress gateway(192, 168, 2, 22);
IPAddress subnet(255, 255, 255, 0);
ESP8266WebServer server(80);
#define IN1 3
#define IN2 4

String webPage = 
{
  "<!DOCTYPE html>"
"<html>"
  "<head>"
    "<title>thi nghiem</title>"
    "<meta charset='utf-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<style>"
      ".b{background-color: green; width: 100px;height: 100px; margin: 10px;}"
      ".t{text-decoration: none;color: white;font-size: 20px;}"
      ".status{font-size: 30px;}"
    "</style>"
  "</head>"

  "<body>"
    "<h1>điều khiển động cơ</h1>"
    "<p class='status'>trạng thái: </p>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/forward'>quay thuận</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button  class='b'>"
        "<a class='t' href='/backward'>quay nghịch</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/s'>dừng</a>"
      "</button>"
    "</div>"
  "</body>"
"</html>"  
};



String webPage_thuan = 
{
  "<!DOCTYPE html>"
"<html>"
  "<head>"
    "<title>thi nghiem</title>"
    "<meta charset='utf-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<style>"
      ".b{background-color: green; width: 100px;height: 100px; margin: 10px;}"
      ".t{text-decoration: none;color: white;font-size: 20px;}"
      ".status{font-size: 30px;}"
    "</style>"
  "</head>"

  "<body>"
    "<h1>điều khiển động cơ</h1>"
    "<p class='status'>trạng thái: quay thuận</p>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/forward'>quay thuận</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button  class='b'>"
        "<a class='t' href='/backward'>quay nghịch</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/s'>dừng</a>"
      "</button>"
    "</div>"
  "</body>"
"</html>"  
};

String webPage_nghich = 
{
  "<!DOCTYPE html>"
"<html>"
  "<head>"
    "<title>thi nghiem</title>"
    "<meta charset='utf-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<style>"
      ".b{background-color: green; width: 100px;height: 100px; margin: 10px;}"
      ".t{text-decoration: none;color: white;font-size: 20px;}"
      ".status{font-size: 30px;}"
    "</style>"
  "</head>"

  "<body>"
    "<h1>điều khiển động cơ</h1>"
    "<p class='status'>trạng thái: quay ngược</p>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/forward'>quay thuận</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button  class='b'>"
        "<a class='t' href='/backward'>quay nghịch</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/s'>dừng</a>"
      "</button>"
    "</div>"
  "</body>"
"</html>"  
};


String webPage_dung = 
{
  "<!DOCTYPE html>"
"<html>"
  "<head>"
    "<title>thi nghiem</title>"
    "<meta charset='utf-8'>"
    "<meta name='viewport' content='width=device-width, initial-scale=1'>"
    "<style>"
      ".b{background-color: green; width: 100px;height: 100px; margin: 10px;}"
      ".t{text-decoration: none;color: white;font-size: 20px;}"
      ".status{font-size: 30px;}"
    "</style>"
  "</head>"

  "<body>"
    "<h1>điều khiển động cơ</h1>"
    "<p class='status'>trạng thái: dừng</p>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/forward'>quay thuận</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button  class='b'>"
        "<a class='t' href='/backward'>quay nghịch</a>"
      "</button>"
    "</div>"
    "<div>"
      "<button class='b'>"
        "<a class='t' href='/s'>dừng</a>"
      "</button>"
    "</div>"
  "</body>"
"</html>"  
};




void handle_client();
void handle_forward();
void handle_backward();
void handle_stop();



void setup() 
{
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_IP, gateway, subnet);
  server.on("/", handle_client);
  Serial.begin(57600);
  server.on("/forward", handle_forward);
  server.on("/backward", handle_backward);
  server.on("/s", handle_stop);
  server.begin();
}




void loop() 
{
  server.handleClient();
 

  

}


void handle_client()
{
  
  server.send(200, "text/html", webPage);
}


void handle_forward()
{
  Serial.println("quay thuan");  
  server.send(200, "text/html", webPage_thuan);
}


void handle_backward()
{
  Serial.println("quay nguoc");  
  server.send(200, "text/html", webPage_nghich);
}


void handle_stop()
{
  Serial.println("dung");  
  server.send(200, "text/html", webPage_dung);
}
