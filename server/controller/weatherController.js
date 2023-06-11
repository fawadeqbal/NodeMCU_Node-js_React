let weather;
import {weatherModel} from '../model/weatherModel.js'
const postWeather = (req, res) => {
  const { temperature, humidity } = req.body;
  weather=req.body;
  
  console.log('Recieved from NodeMCU:', req.body);
  // Send response
  res.send('Data received and saved successfully!');

}

const getWeather= (req,res)=>{
  console.log('Sent to React:', weather);
  res.json(weather);
}
  
export {getWeather,postWeather}