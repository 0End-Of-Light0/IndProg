import React from 'react';
import axios from 'axios';
const Currency = (props) => {
  if (props.curp.indexOf(',') === -1) {
    try {
      
      const response = axios.get('https://025d-2a01-4f9-2a-427-00-2.ngrok-free.app/currency-quote/', { headers: {
        'Access-Control-Allow-Origin': '*',
        'currency-pair': props.curp,
        'period': props.per,
        'interval': props.int,
        'ngrok-skip-browser-warning': true,
        'X-CSRFToken': '1nbZ06juikwvD2wCHLH9KF2oU2605p7QyBsHXola5H35tseN0JoVJyOxl6Rg2jg2'
     }})
      return (
        <div id="Currency">
        <h2>Валюта: {response.curp.Name}</h2>
        <p>Текущий курс: {response.curp.Close}</p>
        </div>
      )
    } catch (error) {
      console.error(error);
    }
  }
  else {
    const listcur = props.curp.split(',');
    let res = <div></div>;
    for (let i = 0; i < listcur.length; i++) {
      try {
        const response = axios.get('https://025d-2a01-4f9-2a-427-00-2.ngrok-free.app/currency-quote/', { headers: {
          'Access-Control-Allow-Origin': '*',
          'currency-pair': listcur[i],
          'period': props.per,
          'interval': props.int,
          'ngrok-skip-browser-warning': true,
          'X-CSRFToken': '1nbZ06juikwvD2wCHLH9KF2oU2605p7QyBsHXola5H35tseN0JoVJyOxl6Rg2jg2'
       }})
        res += <div id="Currency"><h2>Валюта: {response.listcur[i].Name}</h2><p>Текущий курс: {response.listcur[i].Close}</p></div>;
        return (
          res
        )
      } catch (error) {
        console.error(error);
      }
    }
  }
};

export default Currency;
