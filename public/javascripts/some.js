window.onload = function () {
  Currency()
};
const Currency = () => {
  var dstr = "<table><thead><tr><th>CODE</th><th>NAME</th><th>PRICE</th><th>ACTION</th></tr></thead>";
  readTextFile("./json/data.json", function(text){
    var data = JSON.parse(text);
    for (let i = 0; i < data.arr.length; i++) {
      if (data.arr[i].curp.indexOf(',') === -1) {
        try {
          if (data.arr[i].type === "crypto") {
            const hostp = "https://e2c4-2a01-4f9-2a-427-00-2.ngrok-free.app/crypto-currency-quote/"
            const headersp = {
              'Content-Type': 'application/json',
              'crypto-currency-pair': data.arr[i].curp,
              'period': data.arr[i].per,
              'interval': data.arr[i].int,
              'ngrok-skip-browser-warning': 'true'
            }
            fetch(hostp, {
              method: 'GET',
              headers: headersp
            })
            .then(async (response) => {
              return response.json();
            })
            .then(data => {
              console.log(data)
              const res = `<table><thead><tr><th>CODE</th><th>NAME</th><th>PRICE</th><th>ACTION</th></tr></thead><tbody><tr><td>${data.info.currency}</td><td>${data.info.name}</td><td>${data.data[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr></tbody></table>`;
              const sel = '.block' + i
              document.querySelector(sel).innerHTML = res;
            });
          } else {
            const hostp = "https://e2c4-2a01-4f9-2a-427-00-2.ngrok-free.app/currency-quote/"
            const headersp = {
              'Content-Type': 'application/json',
              'currency-pair': data.arr[i].curp,
              'period': data.arr[i].per,
              'interval': data.arr[i].int,
              'ngrok-skip-browser-warning': 'true'
            }
            fetch(hostp, {
              method: 'GET',
              headers: headersp
            })
            .then(async (response) => {
              return response.json();
            })
            .then(data => {
              console.log(data)
              const res = `<table><thead><tr><th>CODE</th><th>NAME</th><th>PRICE</th><th>ACTION</th></tr></thead><tbody><tr><td>${data.info.currency}</td><td>${data.info.name}</td><td>${data.data[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr></tbody></table>`;
              const sel = '.block' + i
              document.querySelector(sel).innerHTML = res;
            });
          }
        } catch (error) {
          console.error(error);
        }
      }
      else {
        const listcur = data.arr[i].curp.split(',');
        const listper = data.arr[i].per.split(',');
        const listint = data.arr[i].int.split(',');
        for (let k = 0; k < listcur.length; k++) {
          try {
            if (data.arr[i].type === "crypto") {
              const hostp = "https://e2c4-2a01-4f9-2a-427-00-2.ngrok-free.app/crypto-currency-quote/"
              const headersp = {
                'Content-Type': 'application/json',
                'crypto-currency-pair': listcur[k],
                'period': listper[k],
                'interval': listint[k],
                'ngrok-skip-browser-warning': 'true'
              }
              fetch(hostp, {
                method: 'GET',
                headers: headersp
                })
                .then(async (response) => {
                  return response.json();
                })
                .then(data => {
                  console.log(data.data[0].Close, data.info.name, data)
                  dstr += `<tbody><tr><td>${data.info.currency}</td><td>${data.info.name}</td><td>${data.data[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr>`;
                });    
            } else {
              const hostp = "https://e2c4-2a01-4f9-2a-427-00-2.ngrok-free.app/currency-quote/"
              const headersp = {
                'Content-Type': 'application/json',
                'currency-pair': listcur[k],
                'period': listper[k],
                'interval': listint[k],
                'ngrok-skip-browser-warning': 'true'
              }
              fetch(hostp, {
                method: 'GET',
                headers: headersp
                })
                .then(async (response) => {
                  return response.json();
                })
                .then(data => {
                  console.log(data.data[0].Close, data.info.name, data)
                  dstr += `<tbody><tr><td>${data.info.currency}</td><td>${data.info.name}</td><td>${data.data[0].Close}</td><td><a href='/chart' class="ButtonWB">open</a></td></tr>`;
                });    
            }      
            } catch (error) {
              console.error(error);
          }
        }
        setTimeout(() => {  document.querySelector(".block" + i).innerHTML += dstr + "</tbody></table>"; }, 11000);
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
