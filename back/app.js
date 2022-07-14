const { SerialPort } = require('serialport');
const http = require('http');

const hostname = '127.0.0.1';
const portRes = 3000;

const port = new SerialPort({
    path: 'COM3',
    baudRate: 9600,
});


const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.end('Hello World');
  port.write('i');
});

server.listen(portRes, hostname, () => {
  console.log(`Server running at http://${hostname}:${portRes}/`);
});

