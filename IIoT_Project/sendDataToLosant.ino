void sendData(int laserDistance, int ultrasonicDistance) {
  
  Serial.println("Sending data!");

  StaticJsonDocument<200> jsonBuffer;
  JsonObject root = jsonBuffer.to<JsonObject>();

  root["laserDist"] = laserDistance;
  root["ultrasonicDist"] = ultrasonicDistance;

  Serial.println("JsonObject to be sent: " );
  serializeJson(root, Serial); // print JSON to serial
  Serial.println("");

  device.sendState(root);

}
