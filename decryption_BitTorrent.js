/*
 * CodeEval Challenge
 * BitTorrent
 * DECRYPTION
 * Ben Postlethwaite
 * post.ben.here@gmail.com
 * 2013
 */

/*
For this challenge you are given an encrypted message and a key. You have to determine the encryption and encoding technique and then print out the corresponding plaintext message. You can assume that the plaintext corresponding to this message, and all messages you must handle, will be comprised of only the characters A-Z and spaces; no digits or punctuation.

Input sample:

There is no input for this program. The encrypted message and key is:

message: "012222 1114142503 0313012513 03141418192102 0113 2419182119021713 06131715070119",
keyed_alphabet: "BHISOECRTMGWYVALUZDNFJKPQX"
Output sample:

Print out the plaintext message. (in CAPS)
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

console.log(decode(message))