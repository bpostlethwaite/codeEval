/*
 * CodeEval Challenge
 * BitTorrent
 * DECRYPTION
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

function decode (msg) {
  var key =  "BHISOECRTMGWYVALUZDNFJKPQX"
  var spacer = "A".charCodeAt(0)

  function bisplit (str) {
    return str.match(/.{1,2}/g)
  }

  function decrypt (digit) {
    var t = String.fromCharCode( parseInt(digit) + spacer )
    return String.fromCharCode( key.indexOf(t) + spacer )
  }

  var decoded = []
  var ss = msg.split(" ").map( bisplit )
  ss.forEach( function (word) {
    decoded.push(word.map( decrypt ).join(""))
  })

  return decoded.join(" ")
}

var message = "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119"

decode(message)