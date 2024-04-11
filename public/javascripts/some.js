window.onload = function () {
  Currency()
};
async function SomeF(i) {
  document.querySelector(".block" + i).innerHTML += "</table></thead>";
}
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
          fetch('https://b1d9-2a01-4f9-2a-427-00-2.ngrok-free.app/test/', {
          method: 'GET',
          headers: {
            'Content-Type': 'application/json',
            'currency-pair': data.arr[i].curp,
            'period': data.arr[i].per,
            'interval': data.arr[i].int,
            'ngrok-skip-browser-warning': 'true'
          }
        })
        .then(async (response) => {
          return response.json();
        })
        .then(data => {
          const res = `<table><thead><tr><th>CODE</th><th>NAME</th><th>PRICE</th><th>ACTION</th></tr></thead><tbody><tr><td>${data.arrs[0].Currency}</td><td>${data.arrs[0].Name}</td><td>${data.arrs[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr></tbody></table>`;
          const sel = '.block' + i
          document.querySelector(sel).innerHTML = res;
        });
        } catch (error) {
          console.error(error);
        }
      }
      else {
        const listcur = data.arr[i].curp.split(',');
        const listper = data.arr[i].per.split(',');
        const listint = data.arr[i].int.split(',');
        document.querySelector(".block" + i).innerHTML = "<table><thead>"
        for (let k = 0; k < listcur.length; k++) {
          try {
            fetch('https://b1d9-2a01-4f9-2a-427-00-2.ngrok-free.app/test/', {
            method: 'GET',
            headers: {
              'Content-Type': 'application/json',
              'currency-pair': listcur[k],
              'period': listper[k],
              'interval': listint[k],
              'ngrok-skip-browser-warning': 'true'
              }
            })
            .then(async (response) => {
              return response.json();
            })
            .then(data => {
              document.querySelector(".block" + i).innerHTML += `<table><thead><tr><th>CODE</th><th>NAME</th><th>PRICE</th><th>ACTION</th></tr></thead><tbody><tr><td>${data.arrs[0].Currency}</td><td>${data.arrs[0].Name}</td><td>${data.arrs[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr></tbody></table>`;
            });          
            } catch (error) {
            console.error(error);
          }
        }
        SomeF(i)
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