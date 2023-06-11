import express from "express";
import bodyParser from "body-parser";
import weather from "./route/weather.js";
import cors from "cors";
import connection from "./db/connection.js";

const app = express();

app.use(cors());
// Parse JSON bodies
app.use(bodyParser.json());

const port = 8080;
connection
  .then(() => {
    console.log("DB Connected.");
  })
  .catch((e) => {
    console.log("Error: ", e);
  });
// Handle the POST request
app.use("/weather", weather);


// Start the server
app.listen(port);
