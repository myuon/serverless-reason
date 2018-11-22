external encode : 'a => Js.Json.t = "%identity";

type handler =
  (
    {. "pathParameters": Js.Dict.t(Js.Json.t)},
    unit,
    (. Js.null(unit), {. "statusCode": int, "body": string}) => Js.Promise.t(unit)
  ) => Js.Promise.t(unit);

let handler : handler = (event, _context, callback) => {
  Js.log("hello");

  callback(. Js.null, {
    "statusCode": 200,
    "body": event##pathParameters |> Js.Dict.unsafeGet(_, "value") |> Js.Json.decodeString |> Js.Option.getExn,
  });
};
