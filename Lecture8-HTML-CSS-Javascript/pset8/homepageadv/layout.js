
let mainLayout = document.getElementById("main");
layout = `
<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- some link from bootstrap -->
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/css/bootstrap.min.css"
        integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@4.0.0/dist/js/bootstrap.min.js"
        integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl"
        crossorigin="anonymous"></script>
    <!-- my css file -->
    <link href="styles.css" rel="stylesheet">
    <title>My Webpage</title>
</head>

<body>
    <div class="container">
        <nav class="navbar">
            <ul class="navbar-nav">
                <li class="nav-item active">
                    <a href="index.html" class="nav-link">Home</a>
                </li>
                <li class="nav-item active">
                    <a href="about.html" class="nav-link">About</a>
                </li>
        </nav>
        <div class="section">
            <div class="mydiv" id="layout">
            </div>
        </div>
    </div>
    <!-- footer -->
    <footer id="footer">
        Copyright &#169; neonpurple
    </footer>
</body>`
document.write(layout);
document.getElementById("layout").appendChild(mainLayout);