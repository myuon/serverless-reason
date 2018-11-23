/* Sorry I'm a lazy person! */
type event = {
  .
  "pathParameters": Js.Dict.t(string),
};

type context = unit;
type callback = (. Js.null(string), Js.Json.t) => Js.Promise.t(unit);

type response = {
  .
  "statusCode": int,
  "body": string,
};

let handler : (event, context, callback) => Js.Promise.t(response) = (event, _, _) => {
  Js.log("hello");

  {
    "statusCode": 200,
    "body": event##pathParameters |> Js.Dict.unsafeGet(_, "value"),
  }
  |> Js.Promise.resolve;
};
