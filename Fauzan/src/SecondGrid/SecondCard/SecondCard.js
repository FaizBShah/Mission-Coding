import React from 'react'
import './SecondCard.css';
export default function SecondCard(props) {
    return (
        <div className="secondcard" data-aos={props.effect}>
            <div className="secondcardImg">
            <img alt="hi" src={props.image} className="secondcardImg"/>
            </div>
            <div className="secondcardText">
                <p className="secondCardHeading">{props.heading}</p>
                <p className="secondcourseLinks">{props.subhead}</p>
        </div>
        </div>
    )
}
