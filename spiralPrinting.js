var fs = require('fs')


var data = fs.readFileSync(process.argv[2]).toString().split("\n")

data.forEach( function (line) {

  var arr = line.split(";")
  if (arr.length < 2) return;

  var N = arr[0]
  var M = arr[1]

  var buff = (arr.slice(2, arr.length)[0]).split(" ")

  printSpiral(buff, buff.length, N, M)
})

function printSpiral(buff, ix, N, M) {

  var pcount = 0
  var row, col
  var n = N
  var m = M
  var s = ""
  while (pcount < ix ) {
    // Along top row
    for (row = N - n, col = M - m; col < m; col++) {
      process.stdout.write(s + buff[ row * M + col ])
      s = " "
      pcount++;
    }
    // Down back side
    if (2 * n - N > 2) {
      for (col = m - 1, row = N - n + 1; row < (n - 1); row++) {
        process.stdout.write(" " + buff[ row * M + col ])
        pcount++;
      }
    }
    if (pcount == ix)
      break;
    // reverse along bottom row
    for (row = n - 1, col = m - 1; col >= (M - m); col--) {
      process.stdout.write(" " + buff[ row * M + col ]);
      pcount++;
    }
    // Up along front side (reverse)
    if (2 * n - N > 2) {
      for (col = M - m, row = n - 2; row >= (N - n + 1) ; row--) {
        process.stdout.write(" " + buff[ row * M + col ]);
        pcount++;
      }
    }
    n--;
    m--;
  }
  process.stdout.write("\n")
}