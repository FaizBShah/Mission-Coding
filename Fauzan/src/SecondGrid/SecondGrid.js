import React from 'react'
import card1 from './card1.PNG'
import card2 from './card2.PNG'
import card3 from './card3.PNG'

import SecondCard from './SecondCard/SecondCard';

import './SecondGrid.css';
export default function SecondGrid() {
    return (
        <div className="SecondGrid">
         <SecondCard image={card1} effect="flip-left" heading="Daily live classes" subhead = "Chat with educators, ask questions, answer live polls, and get your doubts cleared - all while the class is going on"/>  
         <SecondCard image={card2} effect="flip-right" heading="Practice and revise"  subhead = "Learning isn't just limited to classes with our practice section, mock tests and lecture notes shared as PDFs for your revision"/>   
         <SecondCard image={card3} effect="flip-left" heading="Learn anytime anywhere" subhead = "One subscription gets you access to all our live and recorded classes to watch from the comfort of any of your devices"/>   
        </div>
    )
}
