const getData = async () => {
  const data = await fetch("https://www.bogdbank.com/about-bank/report/show", {
    headers: {
      accept: "*/*",
      "accept-language": "en-US,en;q=0.9",
      "content-type": "application/x-www-form-urlencoded; charset=UTF-8",
      "sec-ch-ua": '"Not/A)Brand";v="8", "Chromium";v="126"',
      "sec-ch-ua-mobile": "?1",
      "sec-ch-ua-platform": '"Android"',
      "sec-fetch-dest": "empty",
      "sec-fetch-mode": "cors",
      "sec-fetch-site": "same-origin",
      "x-csrf-token": "yBfvda19RrMWS46qTuCdSjMQgpRRYCsV1u4lMQ9i",
      "x-requested-with": "XMLHttpRequest",
      cookie:
        "_gid=GA1.2.592808788.1719044840; _gat_gtag_UA_165306072_1=1; _ga_1WPWGYZCGT=GS1.1.1719044839.1.1.1719045478.59.0.0; _ga=GA1.1.1577865211.1719044840; XSRF-TOKEN=eyJpdiI6InZZcFNsTGlMd2FuV0I0M0Q0ZTBvVlE9PSIsInZhbHVlIjoiZlA5cVZqZHhnYzdoU3NoS2srWXpnTzEwOE8zRWxWbFNoa0VZQ0lIWGN1NHVBd0p5SGRhSzY1N2RVOE9pUmc1MiIsIm1hYyI6IjgxYTAxM2M4YmJkYWU1NmFhN2UzNWVlMGM3MDhhZWIxYTIxZDQ1NDQ0YTc5OTc2NDQ3N2NhNDRlZmIxYjQyMzIifQ%3D%3D; bogd_session=eyJpdiI6IldSa3J6RU5Fd3ZTSm83djRYcnBiQkE9PSIsInZhbHVlIjoiQ29KenluWm5qK2JQWWRlRUNWdDJHK2RCdFMzNmtyZkNjY1pYRE10eEtKdm40bWVlTHRsMmpodzZPZjlJNDhNbCIsIm1hYyI6IjczYzA5OWNmYWFkYjBhZDdhMjAxNmU5OGZjYzlmYjM5Y2MwZTU2NjBkNjc0NTM1ZmM5ZGRjY2M5YTBhYmEzYjEifQ%3D%3D",
      Referer: "https://www.bogdbank.com/about-bank/6",
      "Referrer-Policy": "strict-origin-when-cross-origin",
    },
    body: "year=2024&season=4-%D1%80+%D1%83%D0%BB%D0%B8%D1%80%D0%B0%D0%BB&category=12",
    method: "POST",
  });
  console.log(await data.json());
  return data;
};

const data = getData();
