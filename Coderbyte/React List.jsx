// React List

import React from 'react';
import ReactDOM from 'react-dom';

function DataList(props) {
  return (
    <div>
      <h2>List :</h2>
      <ul>
        {props.data.map((item, idx) => {
          return (
            <li key={idx}>
              <span>{item.name} </span>
              <span>{item.age}</span>
            </li>
          );
        })}
      </ul>
    </div>
  );
};

const data = [
  { name: 'Daniel', age: 25 },
  { name: 'John', age: 24 },
  { name: 'Jen', age: 31 },
];

ReactDOM.render(
  <DataList data={ data } />,
  document.getElementById('root')
);
