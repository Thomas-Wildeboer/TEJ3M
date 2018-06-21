$(document).ready(function () {
  // IP address of ESP8266
  var address = 'http://192.168.86.111'

  // mouse down event
  $('#forward').mousedown(function () {
    // HTTP request
    $.ajax({
      url: address + '/forward',
      type: 'get',
      crossDomain: true
    })
  })
  $('#forward').mouseup(function () {
    $.ajax({
      url: address + '/stop',
      type: 'get',
      crossDomain: true
    })
  })

  $('#right').mousedown(function () {
    $.ajax({
      url: address + '/right',
      type: 'get',
      crossDomain: true
    })
  })
  $('#right').mouseup(function () {
    $.ajax({
      url: address + '/stop',
      type: 'get',
      crossDomain: true
    })
  })

  $('#left').mousedown(function () {
    $.ajax({
      url: address + '/left',
      type: 'get',
      crossDomain: true
    })
  })
  $('#left').mouseup(function () {
    $.ajax({
      url: address + '/stop',
      type: 'get',
      crossDomain: true
    })
  })

  $('#backward').mousedown(function () {
    $.ajax({
      url: address + '/backward',
      type: 'get',
      crossDomain: true
    })
  })
  $('#backward').mouseup(function () {
    $.ajax({
      url: address + '/stop',
      type: 'get',
      crossDomain: true
    })
  })

  $('#stop').mousedown(function () {
    $.ajax({
      url: address + '/stop',
      type: 'get',
      crossDomain: true
    })
  })
})
