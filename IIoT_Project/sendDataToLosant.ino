void sendData(int laserDist, int ultrasonicDist) {
  
  Serial.println("Sending data!");

  // Losant uses a JSON protocol. Construct the simple state object.
  StaticJsonDocument<200> jsonBuffer;
  JsonObject root = jsonBuffer.to<JsonObject>();
  // send random values to Losant
  root["laserDist"] = laserDist;
  root["ultrasonicDist"] = ultrasonicDist;

  Serial.println("JsonObject to be sent: " );
  serializeJson(root, Serial); // prints json to serial
  Serial.println("");

  // Send the state to Losant.
  device.sendState(root);
}
