import React from 'react'
import Card from './Card/Card'
import card1 from './card1.PNG'
import card2 from './card2.PNG'

import './FirstGrid.css';
export default function FirstGrid() {
    return (
        <div className="FirstGrid">
         <Card highlight="Competitive exams" hooman={card1} effect="fade-up"/>
         <Card highlight="Class 6 to 12" hooman={card2} effect="fade-down"/>   
        </div>
    )
}
