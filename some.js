
window.onload = function () {
  Currency()
};
const Currency = () => {
  readTextFile("./json/data.json", function(text){
    var data = JSON.parse(text);
    //var count = Object.keys(data).length;
    for (let i = 0; i < data.arr.length; i++) {
      //const element =  document.querySelector('.block' + i)
      //const classList = element.classList[0]
      //console.log(classList);
      if (data.arr[i].curp.indexOf(',') === -1) {
        try {
          const response = fetch('https://b1d9-2a01-4f9-2a-427-00-2.ngrok-free.app/test/', {
            method: 'GET',
            headers: {
              'Content-Type': 'application/json',
              'currency-pair': data.arr[i].curp,
              'period': data.arr[i].per,
              'interval': data.arr[i].int,
              'ngrok-skip-browser-warning': 'true'
            }
          });
          const res = "<div id=\"Currency\"><h2>Валюта: " + `${response.arrs[0].Name} + "</h2><p>Текущий курс:" + ${response.arrs[0].Close} + "</p></div>"`;
          document.querySelector('.block' + i).innerHTML = res;
        } catch (error) {
          console.error(error);
        }
      }
      else {
        const listcur = data.arr[i].curp.split(',');
        console.log(listcur);
        let exp = "<div></div>"
        for (let k = 0; k < listcur.length; k++) {
          try {
            const response = fetch('https://b1d9-2a01-4f9-2a-427-00-2.ngrok-free.app/test/', {
            method: 'GET',
            headers: {
              'Content-Type': 'application/json',
              'currency-pair': listcur[k].curp,
              'period': listcur[k].per,
              'interval': listcur[k].int,
              'ngrok-skip-browser-warning': 'true'
            }
            });
            exp +="<div id=\"Currency\"><h2>Валюта: " + `${response.arrs[0].Name} + "</h2><p>Текущий курс:" + ${response.arrs[0].Close} + "</p></div>"`;
          } catch (error) {
            console.error(error);
          }
        document.querySelector('.block' + i).innerHTML = exp;
        }
      }
    }
  });
};
function readTextFile(file, callback) {
  var rawFile = new XMLHttpRequest();
  rawFile.overrideMimeType("application/json");
  rawFile.open("GET", file, true);
  rawFile.onreadystatechange = function() {
      if (rawFile.readyState === 4 && rawFile.status == "200") {
          callback(rawFile.responseText);
      }
  }
  rawFile.send(null);
};
