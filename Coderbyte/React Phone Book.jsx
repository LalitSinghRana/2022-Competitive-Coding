// React Phone Book
import React, { useState, useEffect } from 'react';
import ReactDOM from 'react-dom';

const style = {
  table: {
    borderCollapse: 'collapse'
  },
  tableCell: {
    border: '1px solid gray',
    margin: 0,
    padding: '5px 10px',
    width: 'max-content',
    minWidth: '150px'
  },
  form: {
    container: {
      padding: '20px',
      border: '1px solid #F0F8FF',
      borderRadius: '15px',
      width: 'max-content',
      marginBottom: '40px'
    },
    inputs: {
      marginBottom: '5px'
    },
    submitBtn: {
      marginTop: '10px',
      padding: '10px 15px',
      border:'none',
      backgroundColor: 'lightseagreen',
      fontSize: '14px',
      borderRadius: '5px'
    }
  }
}

function PhoneBookForm({ addEntryToPhoneBook }) {
  const defaultContact = {
    userFirstname: "Coder",
    userLastname: "Byte",
    userPhone: "8885559999"
  }

  const [newContact, setNewContact] = useState(defaultContact);

  const handleContactChange = (e) => {
    setNewContact({
      ...newContact,
      [e.target.name]: e.target.value
    });
  };

  const handleSubmit = (e) => {
    e.preventDefault();
    if(!newContact.userFirstname || !newContact.userLastname || !newContact.userPhone) return;
    addEntryToPhoneBook(newContact);
    setNewContact(defaultContact);
  }

  return (
    <form onSubmit={handleSubmit} style={style.form.container}>
      <label>First name:</label>
      <br />
      <input 
        style={style.form.inputs}
        className='userFirstname'
        name='userFirstname' 
        type='text'
        value={newContact.userFirstname}
        onChange={handleContactChange}
      />
      <br/>
      <label>Last name:</label>
      <br />
      <input 
        style={style.form.inputs}
        className='userLastname'
        name='userLastname' 
        type='text' 
        value={newContact.userLastname}
        onChange={handleContactChange}
      />
      <br />
      <label>Phone:</label>
      <br />
      <input
        style={style.form.inputs}
        className='userPhone' 
        name='userPhone' 
        type='text'
        value={newContact.userPhone}
        onChange={handleContactChange}
      />
      <br/>
      <input 
        style={style.form.submitBtn} 
        className='submitButton'
        type='submit' 
        value='Add User' 
      />
    </form>
  )
}

function InformationTable(props) {
  const sortedContacts = props.list.sort((a,b) => a.userLastname.localeCompare(b.userLastname));

  useEffect(() => {}, [props.list]);

  return (
    <table style={style.table} className='informationTable'>
      <thead> 
        <tr>
          <th style={style.tableCell}>First name</th>
          <th style={style.tableCell}>Last name</th>
          <th style={style.tableCell}>Phone</th>
        </tr>
      </thead> 
      <tbody>{
        sortedContacts.map((itm, idx) => {
          return <tr key={idx}>
            <td style={style.tableCell}>{itm.userFirstname}</td>
            <td style={style.tableCell}>{itm.userLastname}</td>
            <td style={style.tableCell}>{itm.userPhone}</td>
          </tr>
        })
      }</tbody>
    </table>
  );
}

function Application(props) {
  const [list, setList] = useState([]);

  const addEntryToPhoneBook = (newContact) => {
    setList([...list, newContact]);
  }

  return (
    <section>
      <PhoneBookForm addEntryToPhoneBook={addEntryToPhoneBook}/>
      <InformationTable list={list}/>
    </section>
  );
}

ReactDOM.render(
  <Application />,
  document.getElementById('root')
);
