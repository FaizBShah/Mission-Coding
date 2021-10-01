
import './App.css';
import FirstComp from './FirstComp/FirstComp';
import FirstGrid from './FirstGrid/FirstGrid';
import Navbar from './Navbar/Navbar';
import SecondGrid from './SecondGrid/SecondGrid';
import ThirdComp from './ThirdComp/ThirdComp';

function App() {
  return (
    <div >
     <Navbar/>
     <FirstComp/>
     <FirstGrid/>
     <SecondGrid/>
     <ThirdComp/>
    </div>
  );
}

export default App;
