//Loading modules
var http = require('http');
var fs = require('fs');
var path = require('path');
var b = require('bonescript');
var p = require('serialport');

// Create a variable called led, which refers to P9_14
var led = "P9_14";
// Initialize the led as an OUTPUT
b.pinMode(led, b.OUTPUT);

// Initialize the server on port 8888
var server = http.createServer(function (req, res) {
    // requesting files
    var file = '.'+((req.url=='/')?'/index.html':req.url);
    var fileExtension = path.extname(file);
    var contentType = 'text/html';
    // Uncoment if you want to add css to your web page
    /*
    if(fileExtension == '.css'){
        contentType = 'text/css';
    }*/
    fs.exists(file, function(exists){
        if(exists){
            fs.readFile(file, function(error, content){
                if(!error){
                    // Page found, write content
                    res.writeHead(200,{'content-type':contentType});
                    res.end(content);
                }
            })
        }
        else{
            // Page not found
            res.writeHead(404);
            res.end('Page not found');
        }
    })
}).listen(8888);

// Loading socket io module
var io = require('socket.io').listen(server);

// When communication is established
io.on('connection', function (socket) {
    socket.on('changeState',handleChangeState);
    socket.on('writeMDRSTpinConfiguration',handleWriteMDRSTpinConfiguration);
    socket.on('writeHyperSenseSetting',handleWriteHyperSenseSetting);
    socket.on('writeFrequencyResponseSetting',handleWriteFrequencyResponseSetting);
    socket.on('writeMotionDetectionSyspendSetting',handleWriteMotionDetectionSyspendSetting);
    socket.on('writeSerialInterfaceCommandMode',handleWriteSerialInterfaceCommandMode);
    socket.on('writeMotionDetectedUnsolicitedMode',handleWriteMotionDetectedUnsolicitedMode);
    socket.on('writeDualDirectionalMode',handleWriteDualDirectionalMode);
    socket.on('writeSingleDirectionalMode',handleWriteSingleDirectionalMode); //three different modes
    socket.on('moduleReset',handleModuleReset); //single value
    socket.on('sleepMode',handleSleepMode); //single value

    //slider commands
    socket.on('changeSlider',handleChangeSlider);
    socket.on('writeMDactivationTime',handleWriteMDactivationTime); //0-255
    socket.on('writeHyperSenseLevel',handleWriteHyperSenseLevel); //0-3
    socket.on('writeLightGateThreshold',handleWriteLightGateThreshold); //0-255
    socket.on('writeMDoutputState',handleWriteMDoutputState);
    socket.on('writePingValue',handleWritePingValue);
    socket.on('writeRangeSetting',handleWriteRangeSetting); //0-7
    socket.on('writeSensitivity',handleWriteSensitivity);
    socket.on('writeSleepTime',handleWriteSleepTime);
});

function handleChangeSlider(data){
    var newData = data;
    console.log("Slider Changed: " + newData);
}

// Change led state when a button is pressed
function handleChangeState(data) {
    var newData = JSON.parse(data);
    console.log("LED = " + newData.state);
    // turns the LED ON or OFF
    //b.digitalWrite(led, newData.state);
}

    function handleChangeState(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteMDRSTpinConfiguration(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteHyperSenseSetting(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteFrequencyResponseSetting(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteMotionDetectionSyspendSetting(datadata){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteSerialInterfaceCommandMode(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteMotionDetectedUnsolicitedMode(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteDualDirectionalMode(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteSingleDirectionalMode(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //three different modes
    function handleModuleReset(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //single value
    function handleSleepMode(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //single value

    //slider commands
    function handleChangeSlider(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteMDactivationTime(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //0-255
    function handleWriteHyperSenseLevel(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //0-3
    function handleWriteLightGateThreshold(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //0-255
    function handleWriteMDoutputState(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWritePingValue(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteRangeSetting(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    } //0-7
    function handleWriteSensitivity(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
    function handleWriteSleepTime(data){
        var newData = data;
        console.log("Slider changed: " + newData);
    }
// Displaying a console message for user feedback
server.listen(console.log("Server Running ..."));


