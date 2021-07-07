const { exec } = require("child_process");
const { stdin } = require("process");
const filename = "F:\\cpp\\test";
const data = "F:\\cpp\\input.txt";
exec(`g++ ${filename}`, (err, stdout, stderr) => {
  console.log("compiled");
  exec(`${filename}<${data}`, (err, stdout, stderr) => {
    console.log("runned");
    if (err) {
      console.log("there was a problem");
      return;
    }
    console.log(stdout);
  });
});
