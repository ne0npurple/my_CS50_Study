function get_question() {
    return [{
        title: "CD-ROM stands for?",
        options: [{
            description: "Compactable Disc Read Only Memory",
        }, {
            description: "Compact Data Read Only Memory",
        }, {
            description: "Compact Disc Read Only Memory",
        }],
        correct_answer: "Compact Disc Read Only Memory"
    },
    {
        title: "Internal hard disk is?",
        options: [{
            description: "Removable",
        }, {
            description: "Fixed",
        }, {
            description: "Not Fixed",
        }],
        correct_answer: "Fixed"
    }]
}


function get_free_questions() {
    return [{
        title: "Marina Bay Sands is located in?",
        correct_answer: "singapore",
    },
    {
        title: "In which country is it illegal to own only one guinea pig, as a lone guinea pig might get lonely?",
        correct_answer: "switzerland"
    }]
}

function generate_multiple_questions(parent, questions) {
    let list = document.createElement("ol")
    let h3 = document.createElement("h3")
    parent.appendChild(list);
    list.appendChild(h3);
    console.log("questions", questions);
    for (let question of questions) {
        console.log("question", question);
        let numbering = document.createElement("li")
        list.appendChild(numbering);
        let title = document.createElement("h3")
        let result = document.createElement("h3")
        title.innerText = question.title;
        numbering.appendChild(title);
        numbering.appendChild(result);
        let option_buttons = [];
        let option_container = document.createElement("div");
        numbering.appendChild(option_container);
        for (let option of question.options) {
            console.log("question", question);
            let option_button = document.createElement("button");
            option_buttons.push(option_button)
            option_button.innerText = option.description;
            option_container.appendChild(option_button);
            option_button.className = "text_option";
            if (option.description == question.correct_answer) {
                option_button.onclick = function () {
                    for (let button of option_buttons) {
                        button.style.backgroundColor = ""
                    }
                    console.log("click option", option.description);
                    result.innerText = "Correct!"
                    option_button.style.backgroundColor = "#0FFF50";
                }
            } else {
                option_button.onclick = () => {
                    for (let button of option_buttons) {
                        button.style.backgroundColor = ""
                    }
                    console.log("click option", option.description);
                    result.innerText = "Incorrect."
                    option_button.style.backgroundColor = "red";
                }
            }
        }
    }
}

function generate_free_questions(parent, questions) {
    console.log("free question", questions);
    for (let question of questions) {
        console.log("question: ", question);
        // create element for title and result
        let title = document.createElement("h3")
        let result = document.createElement("h3")
        title.innerText = question.title;
        parent.appendChild(title);
        parent.appendChild(result);
        // create the input form for user to type in
        let h3 = document.createElement("h3")
        let inpt = document.createElement("input")
        // set id for inpt form
        inpt.setAttribute("type", "text")
        parent.appendChild(h3);
        h3.appendChild(inpt);
        // create check button
        let check_button = document.createElement("button")
        check_button.innerText = "Check Answer"
        h3.appendChild(check_button)
        // check if answer is correct
        check_button.onclick = () => {
            let answer = inpt.value.toLowerCase();
            console.log("answ: ", answer)
            if (answer == question.correct_answer) {
                result.innerText = "Correct!"
                inpt.style.backgroundColor = "#0FFF50";
            } else {
                result.innerText = "Incorrect."
                inpt.style.backgroundColor = "red";
            }
        }
    }
}
