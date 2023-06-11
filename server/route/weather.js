import express from 'express'
const router = express.Router();
import { getWeather,postWeather } from '../controller/weatherController.js';

router.post("/",postWeather)
router.get("/",getWeather)

export default router;