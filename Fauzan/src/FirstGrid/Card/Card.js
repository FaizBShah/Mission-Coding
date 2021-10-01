import React from 'react'
import './Card.css';
export default function Card(props) {
    return (
        <div className="card" data-aos={props.effect}>
            <div className="cardText">
                <p className="CardHeading">Prepare for <br/><strong>{props.highlight}</strong></p>
                <p className="courseLinks">Popular goals</p>
                <p className="courseLinks">
                <a href="/">UPSC CSE - GS</a> <a href="/">IIT JEE </a> <a href="/">NEET UG</a> 
                <a href="/">Bank Exams</a> <a href="/">GATE & ESE</a> <a href="/">UPSC CSE - Optional</a>
                </p>
                <button className="UnacademyBtn">Start Learning</button>
            </div>
            <div className="cardImg">
            <img src={props.hooman} alt="hi" className="cardimg"/>
            </div>
        </div>
    )
}
