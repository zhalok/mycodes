const parseMessage = require("gmail-api-parse-message");
const response = require("./response.json");
var parsedMessage = parseMessage(response);
console.log(parsedMessage.textPlain);
