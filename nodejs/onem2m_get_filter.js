// Created by J. Yun, SCH Univ., yun@sch.ac.kr
// Need to install node-fetch
// $ npm i node-fetch --save

const fetch = require("node-fetch");

var myHeaders = new fetch.Headers();
myHeaders.append("Accept", "application/json");
myHeaders.append("X-M2M-RI", "12345");
myHeaders.append("X-M2M-Origin", "sch20181498_");

var requestOptions = {
  method: 'GET',
  headers: myHeaders,
  redirect: 'follow'
};

// uncomment one of three .url statements below
// 1. retrieve latest three cins
fetch("http://203.253.128.161:7579/Mobius/sch20181498_/dust?fu=2&la=3&ty=4&rcn=4", 
      requestOptions)
	
// 2. retrieve three cins created after ct=20210512T100525
// fetch("http://203.253.128.161:7579/Mobius/sch19999999/dust?fu=2&lim=3&ty=4&rcn=4"
//       + "&cra=20210512T100525", requestOptions)
			
// 3. retrieve three cins created after ct=20210512T100525 and before ct=20210512T100540
// fetch("http://203.253.128.161:7579/Mobius/sch19999999/dust?fu=2&ty=4&rcn=4"
//       + "&cra=20210512T100525&crb=20210512T100540", requestOptions)

  .then(
    function(response) {
      if (response.status !== 200) {
        console.log('There was a problem. Status Code: ' +
          response.status);
        return;
      }

      response.json().then(function(data) {
        console.log(data['m2m:rsp']['m2m:cin']);
        for (var i = 0; i < data['m2m:rsp']['m2m:cin'].length; i++) {
          // console.log(data['m2m:rsp']['m2m:cin'][i]);
          var key = data['m2m:rsp']['m2m:cin'][i];
          console.log(key.con);
        }
      });
    }
  )
  .catch(function(err) {
    console.log('Fetch Error :-S', err);
  });