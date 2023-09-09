const assert = require('assert');
const { print, setTargetWindow, setTargetWindowHwnd, getWindowHwnd } = require('./');

console.log(print("test"));
// console.info(setTargetWindow("Windows PowerShell"))
// console.info(getWindowHwnd("Windows PowerShell"))
console.info(setTargetWindowHwnd("264892"))