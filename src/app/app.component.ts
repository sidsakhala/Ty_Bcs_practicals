import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'ptest';

  courseNames = [
    'Angular',
    'Machine Learning',
    'Next Generation Databases',
    'Lab on Angular',
    'Lab on ML',
  ];

}
