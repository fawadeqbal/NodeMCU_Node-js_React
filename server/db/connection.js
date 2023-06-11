import mongoose from "mongoose";
const url='mongodb+srv://fawad:1111@clusterstore.wuakt30.mongodb.net/?retryWrites=true&w=majority'
const connection = mongoose.connect(url,{
    useNewUrlParser:true,useUnifiedTopology:true
})

export default connection;