// module.exports = require('bindings')('addon');

console.info('dirname: ', __dirname)

// module.exports = require('node-gyp-build')(__dirname)
module.exports = require('node-gyp-build')("../sunshot-recorder")
