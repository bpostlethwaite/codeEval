var p = require("printarray");
var at = require("arraytools");


var nx = 6
var ny = 2



var a = []

for (var i = 1; i <= nx*ny; i++)
  a[i-1] = i


if (process.argv[2] === "-p")
  p(a, 4, [nx, ny])

if (process.argv[2] === "-w") {
  process.stdout.write(nx + ";" + ny + ";")
  process.stdout.write(a.join(" "))
  process.stdout.write("\n")
}