const { exec } = require("child_process");
const { stdin } = require("process");
const filename = "F:\\cpp\\test";
const data = "F:\\cpp\\input.txt";
exec(`${filename}<${data}`, { prompt: "cmd.exe" }, (err, stdout, stderr) => {
  // console.log("compiled");
  console.log(stdout);
});

// const fs = require("fs");
// console.log(fs);
// fs.writeFileSync("Hello.txt", "Hello guys\n");
// fs.appendFileSync("Hello.txt", " hi");
