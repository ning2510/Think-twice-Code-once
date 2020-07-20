﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Delete.aspx.cs" Inherits="work_Delete" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <!-- 新 Bootstrap4 核心 CSS 文件 -->
    <link rel="stylesheet" href="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css" />

    <!-- jQuery文件。务必在bootstrap.min.js 之前引入 -->
    <script src="https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js"></script>

    <!-- bootstrap.bundle.min.js 用于弹窗、提示、下拉菜单，包含了 popper.min.js -->
    <script src="https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js"></script>

    <!-- 最新的 Bootstrap4 核心 JavaScript 文件 -->
    <script src="https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js"></script>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <title>删除用户</title>
</head>
<body style="background-image: url('../work/333.png'); background-repeat:no-repeat;background-size:100% 100%;background-attachment: fixed;">
    <form id="form1" runat="server">
        <div>
            <nav class="navbar navbar-expand-lg navbar-light shadow p-3 mb-5 bg-white rounded btn bg-danger">
                <a class="navbar-brand text-black" href="jiemian.aspx">Comment System</a>
                <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarText" aria-controls="navbarText" aria-expanded="false" aria-label="Toggle navigation">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarText">
                    <ul class="navbar-nav mr-auto">
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="jiemian.aspx">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="14" height="14">
                                    <path d="M12.9705 2.58982C12.4107 2.11484 11.5893 2.11484 11.0295 2.58982L3.52953 8.95345C3.19364 9.23846 3 9.6567 3 10.0972V19.5C3 20.3284 3.67157 21 4.5 21H9.25C9.66421 21 10 20.6642 10 20.25V14H14V20.25C14 20.6642 14.3358 21 14.75 21H19.5C20.3284 21 21 20.3284 21 19.5V10.0972C21 9.6567 20.8064 9.23846 20.4705 8.95345L12.9705 2.58982Z">
                                    </path>
                                </svg>
                                Home <span class="sr-only">(current)</span>
                            </a>
                        </li>
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="管理登录.aspx">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" width="14" height="14">
                                    <path fill-rule="evenodd" clip-rule="evenodd" d="M14.064 0C11.7434 9.77766e-05 9.51786 0.922034 7.87699 2.563L7.41799 3.021C7.10399 3.335 6.80199 3.662 6.51399 4H3.30999C3.01117 4.00009 2.71736 4.07669 2.45653 4.2225C2.19571 4.36832 1.97657 4.57849 1.81999 4.833L0.10999 7.607C0.0499638 7.7045 0.0130574 7.81445 0.00209983 7.92842C-0.00885773 8.04239 0.00642442 8.15736 0.0467749 8.26451C0.0871255 8.37166 0.151473 8.46815 0.234886 8.54658C0.318298 8.62502 0.418561 8.68331 0.52799 8.717L3.62999 9.671C3.66699 9.722 3.70899 9.771 3.75399 9.816L6.18299 12.244C6.22899 12.29 6.27699 12.332 6.32799 12.369L7.28199 15.471C7.31568 15.5804 7.37397 15.6807 7.45241 15.7641C7.53084 15.8475 7.62733 15.9119 7.73448 15.9522C7.84163 15.9926 7.9566 16.0078 8.07057 15.9969C8.18454 15.9859 8.29449 15.949 8.39199 15.889L11.166 14.182C11.4205 14.0254 11.6307 13.8063 11.7765 13.5455C11.9223 13.2846 11.9989 12.9908 11.999 12.692V9.485C12.337 9.197 12.664 8.895 12.978 8.581L13.436 8.122C15.0771 6.48154 15.9994 4.2564 16 1.936V1.75C16 1.28587 15.8156 0.840752 15.4874 0.512563C15.1592 0.184374 14.7141 0 14.25 0H14.064ZM10.5 10.625C10.412 10.685 10.323 10.743 10.234 10.8L7.88399 12.321L8.43199 14.104L10.381 12.904C10.4174 12.8816 10.4474 12.8503 10.4682 12.813C10.4891 12.7757 10.5 12.7337 10.5 12.691V10.625ZM3.67799 8.116L5.19999 5.766C5.25799 5.676 5.31699 5.588 5.37599 5.5H3.30899C3.26628 5.49999 3.22427 5.51092 3.18699 5.53175C3.1497 5.55258 3.11837 5.58262 3.09599 5.619L1.89599 7.569L3.67799 8.116ZM8.93799 3.623C10.2973 2.26391 12.1408 1.50028 14.063 1.5H14.249C14.3153 1.5 14.3789 1.52634 14.4258 1.57322C14.4727 1.62011 14.499 1.6837 14.499 1.75V1.936C14.4991 2.88813 14.3117 3.83096 13.9474 4.71066C13.5832 5.59035 13.0492 6.38968 12.376 7.063L11.917 7.521C11.157 8.281 10.32 8.958 9.41799 9.541L7.10099 11.041L4.95799 8.898L6.45799 6.581C7.04138 5.67884 7.71847 4.84085 8.47799 4.081L8.93599 3.623H8.93799ZM12 5C12 5.26522 11.8946 5.51957 11.7071 5.70711C11.5196 5.89464 11.2652 6 11 6C10.7348 6 10.4804 5.89464 10.2929 5.70711C10.1053 5.51957 9.99999 5.26522 9.99999 5C9.99999 4.73478 10.1053 4.48043 10.2929 4.29289C10.4804 4.10536 10.7348 4 11 4C11.2652 4 11.5196 4.10536 11.7071 4.29289C11.8946 4.48043 12 4.73478 12 5ZM3.55999 14.56C3.70736 14.4227 3.82557 14.2571 3.90755 14.0731C3.98954 13.8891 4.03362 13.6905 4.03717 13.489C4.04073 13.2876 4.00368 13.0876 3.92824 12.9008C3.85279 12.714 3.7405 12.5444 3.59807 12.4019C3.45563 12.2595 3.28596 12.1472 3.09919 12.0718C2.91241 11.9963 2.71235 11.9593 2.51095 11.9628C2.30954 11.9664 2.11091 12.0105 1.92691 12.0924C1.74292 12.1744 1.57731 12.2926 1.43999 12.44C0.70599 13.17 0.39299 14.772 0.28999 15.443C0.2839 15.4792 0.286547 15.5163 0.29771 15.5512C0.308873 15.5861 0.328229 15.6179 0.354162 15.6438C0.380096 15.6698 0.411855 15.6891 0.44679 15.7003C0.481726 15.7114 0.518824 15.7141 0.55499 15.708C1.22599 15.605 2.82799 15.292 3.55999 14.56Z">
                                    </path>
                                </svg>
                                Admin</a>
                        </li>
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="用户登录.aspx">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" width="14" height="14">
                                    <path fill-rule="evenodd" clip-rule="evenodd" d="M5.49999 3.5C4.96956 3.5 4.46085 3.71071 4.08578 4.08578C3.71071 4.46086 3.49999 4.96956 3.49999 5.5C3.49999 6.03043 3.71071 6.53914 4.08578 6.91421C4.46085 7.28928 4.96956 7.5 5.49999 7.5C6.03042 7.5 6.53913 7.28928 6.91421 6.91421C7.28928 6.53914 7.49999 6.03043 7.49999 5.5C7.49999 4.96956 7.28928 4.46086 6.91421 4.08578C6.53913 3.71071 6.03042 3.5 5.49999 3.5ZM1.99999 5.5C1.99992 4.91987 2.14405 4.34882 2.41942 3.83821C2.69479 3.32761 3.09276 2.89346 3.57754 2.57481C4.06232 2.25616 4.61871 2.06301 5.19665 2.01274C5.7746 1.96246 6.35598 2.05663 6.8885 2.28677C7.42102 2.51692 7.88799 2.87582 8.24739 3.33121C8.6068 3.78659 8.84738 4.32417 8.94749 4.89559C9.0476 5.46702 9.0041 6.05437 8.8209 6.60481C8.63771 7.15525 8.32056 7.65153 7.89799 8.049C8.69485 8.43558 9.38671 9.00867 9.91488 9.71963C10.4431 10.4306 10.792 11.2585 10.932 12.133C10.9632 12.3295 10.915 12.5304 10.798 12.6914C10.6811 12.8524 10.505 12.9603 10.3085 12.9915C10.112 13.0227 9.91111 12.9745 9.75011 12.8575C9.58911 12.7406 9.48115 12.5645 9.44999 12.368C9.29867 11.4294 8.81804 10.5753 8.09424 9.95882C7.37043 9.34235 6.45074 9.00379 5.49999 9.00379C4.54924 9.00379 3.62956 9.34235 2.90575 9.95882C2.18194 10.5753 1.70131 11.4294 1.54999 12.368C1.5345 12.4653 1.49998 12.5586 1.44843 12.6426C1.39687 12.7266 1.32928 12.7996 1.24952 12.8574C1.16975 12.9153 1.07937 12.9568 0.983542 12.9797C0.88771 13.0027 0.788301 13.0065 0.690991 12.991C0.593682 12.9755 0.500377 12.941 0.416405 12.8894C0.332433 12.8379 0.259438 12.7703 0.201587 12.6905C0.143736 12.6108 0.102162 12.5204 0.07924 12.4245C0.0563177 12.3287 0.0524954 12.2293 0.0679914 12.132C0.208326 11.2578 0.557366 10.4304 1.08552 9.71976C1.61368 9.00917 2.30538 8.4364 3.10199 8.05C2.75352 7.72304 2.4759 7.328 2.28635 6.88937C2.09679 6.45073 1.99932 5.97784 1.99999 5.5ZM11 4C10.8011 4 10.6103 4.07901 10.4697 4.21967C10.329 4.36032 10.25 4.55108 10.25 4.75C10.25 4.94891 10.329 5.13967 10.4697 5.28033C10.6103 5.42098 10.8011 5.5 11 5.5C11.3383 5.50002 11.6667 5.61443 11.9319 5.82465C12.197 6.03487 12.3833 6.32854 12.4604 6.65798C12.5375 6.98742 12.501 7.33327 12.3568 7.63934C12.2126 7.94542 11.9692 8.19375 11.666 8.344C11.541 8.40618 11.4358 8.50203 11.3623 8.62075C11.2888 8.73948 11.2499 8.87636 11.25 9.016V9.368C11.2498 9.53646 11.3063 9.70009 11.4104 9.83252C11.5145 9.96495 11.6602 10.0585 11.824 10.098C13.024 10.387 13.986 11.298 14.346 12.47C14.3745 12.5645 14.4215 12.6525 14.4841 12.7289C14.5468 12.8052 14.6239 12.8685 14.7111 12.915C14.7982 12.9614 14.8937 12.9902 14.992 12.9997C15.0903 13.0092 15.1895 12.9991 15.284 12.9702C15.3784 12.9412 15.4662 12.8939 15.5422 12.8309C15.6183 12.7679 15.6812 12.6905 15.7273 12.6031C15.7734 12.5158 15.8018 12.4202 15.8108 12.3218C15.8199 12.2235 15.8094 12.1243 15.78 12.03C15.5798 11.3806 15.2496 10.7787 14.8095 10.261C14.3694 9.74317 13.8286 9.32028 13.22 9.018C13.6109 8.58794 13.8686 8.05357 13.9615 7.47985C14.0545 6.90613 13.9788 6.31776 13.7437 5.78625C13.5085 5.25474 13.124 4.80298 12.637 4.48587C12.1499 4.16876 11.5812 3.99996 11 4Z">
                                    </path>
                                </svg>
                                User</a>
                        </li>
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="Add.aspx">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" width="14" height="14">
                                    <path fill-rule="evenodd" clip-rule="evenodd" d="M1.5 8C1.5 4.41015 4.41015 1.5 8 1.5C11.5899 1.5 14.5 4.41015 14.5 8C14.5 11.5899 11.5899 14.5 8 14.5C4.41015 14.5 1.5 11.5899 1.5 8ZM8 0C3.58172 0 0 3.58172 0 8C0 12.4183 3.58172 16 8 16C12.4183 16 16 12.4183 16 8C16 3.58172 12.4183 0 8 0ZM8.75 4.75C8.75 4.33579 8.41421 4 8 4C7.58579 4 7.25 4.33579 7.25 4.75V7.25H4.75C4.33579 7.25 4 7.58579 4 8C4 8.41421 4.33579 8.75 4.75 8.75H7.25V11.25C7.25 11.6642 7.58579 12 8 12C8.41421 12 8.75 11.6642 8.75 11.25V8.75H11.25C11.6642 8.75 12 8.41421 12 8C12 7.58579 11.6642 7.25 11.25 7.25H8.75V4.75Z">
                                    </path>
                                </svg>
                                Add</a>
                        </li>
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="#">
                                 <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="14" height="14">
                                    <path fill-rule="evenodd" clip-rule="evenodd" d="M16 1.75V3H21.25C21.6642 3 22 3.33579 22 3.75C22 4.16421 21.6642 4.5 21.25 4.5H2.75C2.33579 4.5 2 4.16421 2 3.75C2 3.33579 2.33579 3 2.75 3H8V1.75C8 0.783502 8.7835 0 9.75 0H14.25C15.2165 0 16 0.783502 16 1.75ZM9.5 1.75C9.5 1.61193 9.61193 1.5 9.75 1.5H14.25C14.3881 1.5 14.5 1.61193 14.5 1.75V3H9.5V1.75Z"></path>
                                    <path d="M4.99657 6.17775C4.95667 5.76546 4.5901 5.46358 4.17781 5.50348C3.76552 5.54338 3.46364 5.90995 3.50354 6.32224L4.91609 20.9186C5.0029 21.8156 5.75674 22.5 6.65795 22.5H17.3422C18.2434 22.5 18.9972 21.8156 19.084 20.9186L20.4966 6.32224C20.5365 5.90995 20.2346 5.54338 19.8223 5.50348C19.41 5.46358 19.0434 5.76546 19.0035 6.17775L17.591 20.7741C17.5786 20.9022 17.4709 21 17.3422 21H6.65795C6.52921 21 6.42151 20.9022 6.40911 20.7741L4.99657 6.17775Z"></path>
                                    <path d="M9.20598 7.50129C9.61948 7.47696 9.97441 7.79245 9.99873 8.20595L10.4987 16.706C10.5231 17.1194 10.2076 17.4744 9.79406 17.4987C9.38057 17.523 9.02564 17.2075 9.00132 16.794L8.50132 8.29403C8.47699 7.88054 8.79248 7.52561 9.20598 7.50129Z"></path>
                                    <path d="M15.4987 8.29403C15.5231 7.88054 15.2076 7.52561 14.7941 7.50129C14.3806 7.47696 14.0256 7.79245 14.0013 8.20595L13.5013 16.706C13.477 17.1194 13.7925 17.4744 14.206 17.4987C14.6195 17.523 14.9744 17.2075 14.9987 16.794L15.4987 8.29403Z"></path></svg>
                                Delete</a>
                        </li>
                        <li class="nav-item active">
                            <a class="nav-link text--black" href="Modify.aspx">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 16 16" width="14" height="14">
                                    <path fill-rule="evenodd" clip-rule="evenodd" d="M11.0126 1.42678C11.696 0.74336 12.804 0.743362 13.4874 1.42678L14.5732 2.51257C15.2566 3.19598 15.2566 4.30402 14.5732 4.98744L5.96355 13.5971C5.75325 13.8074 5.49283 13.9606 5.20687 14.0423L1.95603 14.9711C1.69413 15.046 1.41226 14.9729 1.21966 14.7803C1.02706 14.5877 0.954017 14.3059 1.02884 14.044L1.95766 10.7931C2.03936 10.5072 2.19259 10.2467 2.40289 10.0364L11.0126 1.42678ZM12.4268 2.48744C12.3291 2.38981 12.1708 2.38981 12.0732 2.48744L10.8106 3.75L12.25 5.18934L13.5126 3.92678C13.6102 3.82915 13.6102 3.67086 13.5126 3.57323L12.4268 2.48744ZM11.1893 6.25L9.74999 4.81066L3.46355 11.0971C3.43351 11.1271 3.41162 11.1643 3.39994 11.2052L2.842 13.158L4.79479 12.6C4.83564 12.5884 4.87284 12.5665 4.90289 12.5364L11.1893 6.25Z">
                                    </path>
                                </svg>
                                Modify</a>
                        </li>
                        <li class="nav-item active">
                                <a class="nav-link text--black" href="write.aspx">
                                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="14" height="14">
                                        <path fill-rule="evenodd" clip-rule="evenodd" d="M0 4.75C0 3.7835 0.783502 3 1.75 3H22.25C23.2165 3 24 3.7835 24 4.75V19.25C24 20.2165 23.2165 21 22.25 21H1.75C0.783502 21 0 20.2165 0 19.25V4.75ZM1.75 4.5C1.61193 4.5 1.5 4.61193 1.5 4.75V19.25C1.5 19.3881 1.61193 19.5 1.75 19.5H22.25C22.3881 19.5 22.5 19.3881 22.5 19.25V4.75C22.5 4.61193 22.3881 4.5 22.25 4.5H1.75Z"></path>
                                        <path fill-rule="evenodd" clip-rule="evenodd" d="M5 8.75C5 8.33579 5.33579 8 5.75 8H17.25C17.6642 8 18 8.33579 18 8.75C18 9.16421 17.6642 9.5 17.25 9.5H5.75C5.33579 9.5 5 9.16421 5 8.75Z"></path>
                                        <path fill-rule="evenodd" clip-rule="evenodd" d="M5 12.75C5 12.3358 5.33579 12 5.75 12H11.25C11.6642 12 12 12.3358 12 12.75C12 13.1642 11.6642 13.5 11.25 13.5H5.75C5.33579 13.5 5 13.1642 5 12.75Z"></path></svg>
                                    Content</a>
                            </li>
                            <li class="nav-item active">
                                <a class="nav-link text--black" href="Account.aspx">
                                    <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" width="14" height="14">
                                        <path fill-rule="evenodd" clip-rule="evenodd" d="M12 2.5C8.96251 2.5 6.50012 4.96245 6.50012 8C6.50012 9.88946 7.45289 11.5564 8.90419 12.5466C5.53963 13.7791 3.11605 16.9629 3.004 20.7277C2.99168 21.1417 3.31733 21.4873 3.73136 21.4997C4.14539 21.512 4.49101 21.1863 4.50334 20.7723C4.62347 16.7357 7.93397 13.5 12 13.5C16.0659 13.5 19.3764 16.7357 19.4966 20.7723C19.5089 21.1863 19.8545 21.512 20.2685 21.4997C20.6826 21.4873 21.0082 21.1417 20.9959 20.7277C20.8839 16.963 18.4603 13.7791 15.0958 12.5466C16.5472 11.5564 17.5 9.88949 17.5 8C17.5 4.96245 15.0376 2.5 12 2.5ZM8.00012 8C8.00012 5.79085 9.79096 4 12 4C14.2091 4 16 5.79085 16 8C16 10.2092 14.2091 12 12 12C9.79096 12 8.00012 10.2092 8.00012 8Z">
                                        </path>
                                    </svg>
                                    Account</a>
                            </li>
                    </ul>
                    <div class="btn-group">
                        <button type="button" class="btn btn-white dropdown-toggle" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                            Admin
                        </button>
                        <div class="dropdown-menu">
                            <a class="dropdown-item" href="jiemian.aspx">Logout</a>
                        </div>
                    </div>
                </div>
            </nav>
            <div class="jumbotron">
                <h1 class="display-4">Hello, dear admin user!</h1>
                <p class="lead">This is delete user mode. Please enter the account you want to delete.</p>
                <hr class="my-4" />
                <div class="form-group row">
                    <label class="col-sm-2 col-form-label">Username</label>
                    <div class="col-sm-5">
                        <asp:TextBox ID="TextBox1" runat="server" class="form-control"></asp:TextBox>
                    </div>
                </div>
                <div class="form-group row">
                    <div class="col-sm-10">
                        <asp:Button ID="Button2" runat="server" Text="删除" OnClick="Button2_Click" class="btn btn-danger" />
                    </div>
                </div>
            </div>
        </div>
    </form>
</body>
</html>
